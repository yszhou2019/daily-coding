class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 1), suf(n, 1);
        for (int i = 0; i < n; i++)
            pre[i] = (i == 0 ? 1 : pre[i - 1]) * nums[i];
        for (int i = n - 1; i >= 0; i--)
            suf[i] = (i == n - 1 ? 1 : suf[i + 1]) * nums[i];

        vector<int> res(n, 0);
        res[0] = suf[1];
        res[n - 1] = pre[n - 2];
        for (int i = 1; i < n - 1; i++)
            res[i] = pre[i - 1] * suf[i + 1];
        return res;
    }
};