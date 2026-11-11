class Solution {
public:
    using ll = long long;
    int minSizeSubarray(vector<int>& nums, int target) {
        ll sum = accumulate(nums.begin(), nums.end(), static_cast<ll>(0));
        int cnt = target / sum;
        target = target % sum;
        if (target == 0)
            return cnt * nums.size();

        int n = nums.size();
        vector<ll> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + nums[i];

        unordered_map<ll, int> hash{}; //  prefix sum -> right index
        hash[0] = -1;
        int res1{}, res2{INT_MAX};
        for (int i = 0; i < n; i++) {
            ll t = pre[i] + target - sum;
            if (auto it = hash.find(t); it != hash.end())
                res1 = max(res1, i - it->second);
            if (auto it = hash.find(pre[i] - target); it != hash.end())
                res2 = min(res2, i - it->second);
            hash[pre[i]] = i;
        }

        if (res1 == 0 && res2 == INT_MAX)
            return -1;
        int len1 = (ll)(cnt + 1) * n - res1;
        int len2 = (ll)cnt * n + res2;
        if (res1 == 0)
            return len2;
        if (res2 == INT_MAX)
            return len1;
        return min(len1, len2);
    }
};