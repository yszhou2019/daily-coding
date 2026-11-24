class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        for (int i = 0; i < n; i++)
            pre[i] = (i == 0 ? 0 : pre[i - 1]) + nums[i];
        int tot = pre[n - 1];

        vector<int> res(n);
        for (int i = 0; i < n; i++)
            res[i] = abs(2 * pre[i] - tot - nums[i]);
        return res;
    }
};