class Solution {
public:
    using ll = long long;
    int minSubarray(vector<int>& nums, int p) {
        ll sum = accumulate(nums.begin(), nums.end(), static_cast<ll>(0));
        if (sum % p == 0)
            return 0;
        int n = nums.size();
        vector<ll> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + nums[i];

        int res{INT_MAX};
        unordered_map<int, int> hash{};
        hash[0] = -1;
        for (int i = 0; i < n; i++) {
            int target = ((pre[i] - sum) % p + p) % p;
            if (auto it = hash.find(target); it != hash.end())
                res = min(res, i - it->second);
            hash[pre[i] % p] = i;
        }
        if (res == INT_MAX || res == n)
            return -1;
        return res;
    }
};