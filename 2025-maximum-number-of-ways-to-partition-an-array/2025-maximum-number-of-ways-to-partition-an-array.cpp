class Solution {
public:
    using ll = long long;
    int waysToPartition(vector<int>& nums, int k) {
        ll total = accumulate(nums.begin(), nums.end(), 0ll);

        int n = nums.size();
        vector<ll> pre(n), suf(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + nums[i];
        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suf[i] = suf[i + 1] + nums[i];

        // prefix/suffix sum (of original subarray) -> count
        unordered_map<ll, int> hash{};
        vector<int> res(n); // # of ways after changing i-th to k

        // part-1: after changing i-th to k
        for (int i = 0; i < n; i++) {
            ll tot = total - nums[i] + k;
            if (tot % 2 == 0)
                res[i] += hash[tot / 2];
            hash[pre[i]]++;
        }
        hash.clear();

        // part-2: after changing i-th to k
        for (int i = n - 1; i >= 0; i--) {
            ll tot = total - nums[i] + k;
            if (tot % 2 == 0)
                res[i] += hash[tot / 2];
            hash[suf[i]]++;
        }

        // array unchanged
        int res1{};
        for (int i = 0; i < n - 1; i++) // n-1 instead of n
            if (pre[i] * 2 == total)
                res1++;

        int res0 = *max_element(res.begin(), res.end());
        return max(res0, res1);
    }
};