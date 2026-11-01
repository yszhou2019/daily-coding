class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 0);
        int tot = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < n; i++)
            pre[i] = (i == 0 ? 0 : pre[i - 1]) + nums[i];

        for (int i = 0; i < n; i++)
            if ((i == 0 ? 0 : pre[i - 1]) == tot - pre[i])
                return i;
        return -1;
    }
};