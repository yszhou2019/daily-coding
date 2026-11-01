class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + nums[i];

        unordered_map<int, int> hash{}; // prefix sum and subarray count
        hash[0] = 1;
        int res{};
        for (int i = 0; i < n; i++) {
            int target = pre[i] - goal;
            auto it = hash.find(target);
            if (it != hash.end())
                res += it->second;
            hash[pre[i]]++;
        }
        return res;
    }
};