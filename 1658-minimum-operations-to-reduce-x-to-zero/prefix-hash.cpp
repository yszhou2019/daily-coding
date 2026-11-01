class Solution {
public:
    using ll = long long;
    int minOperations(vector<int>& nums, int x) {
        ll sum = accumulate(nums.begin(), nums.end(), static_cast<ll>(0));
        if (sum < x)
            return -1;
        int n = nums.size();
        if (sum == x)
            return n;

        vector<ll> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + nums[i];

        unordered_map<ll, int> hash{}; // prefix -> index
        hash[0] = -1;
        int res{-1};
        for (int i = 0; i < n; i++) {
            ll target = pre[i] - sum + x;
            if (auto it = hash.find(target); it != hash.end())
                res = max(res, i - it->second);
            if (hash.find(pre[i]) == hash.end())
                hash[pre[i]] = i;
        }
        if (res == -1)
            return -1;
        return n - res;
    }
};