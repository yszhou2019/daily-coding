class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + nums[i];

        int res{};
        unordered_map<int, int> hash{};
        hash[0] = 1;
        for (int r = 0; r < n; r++) {
            res += hash[pre[r] - k];
            hash[pre[r]]++;
        }
        return res;
    }
};