class Solution {
public:
    using ll = long long;
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<ll> pre(n, 0ll);
        for (int i = 0; i < n; i++)
            pre[i] = (i == 0 ? 0 : pre[i - 1]) + nums[i];

        ll tot{pre[n - 1]};
        int record{INT_MAX}, idx{};
        for (int i = 0; i < n - 1; i++) {
            int diff = abs(pre[i] / (i + 1) - (tot - pre[i]) / (n - i - 1));
            if (diff < record) {
                record = diff;
                idx = i;
            }
        }
        if (tot / n < record)
            idx = n - 1;
        return idx;
    }
};