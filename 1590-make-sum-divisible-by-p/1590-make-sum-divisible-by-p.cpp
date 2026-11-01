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

        auto mod = [p](ll x) { return (x % p + p) % p; };

        int res{INT_MAX};
        unordered_map<ll, int> hash{};
        hash[0] = -1;
        ll m = mod(sum);
        for (int i = 0; i < n; i++) {
            ll target = (mod(pre[i]) - m + p) % p;
            auto it = hash.find(target);
            if (it != hash.end())
                res = min(res, i - it->second);
            hash[mod(pre[i])] = i;
        }
        if (res == n || res == INT_MAX)
            return -1;
        return res;
    }
};