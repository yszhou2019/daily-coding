class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2)
            return false;
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + nums[i];

        unordered_map<int, int> hash{};
        hash[0] = -1;

        int len{};

        for (int i = 0; i < n; i++) {
            auto target = pre[i] % k;
            if (auto it = hash.find(target); it != hash.end())
                len = max(len, i - it->second);
            else
                hash[target] = i;
        }
        return len > 1;
    }
};