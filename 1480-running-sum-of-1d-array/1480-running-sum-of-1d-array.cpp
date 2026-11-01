class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++)
            res[i] = (i == 0 ? 0 : res[i - 1]) + nums[i];
        return res;
    }
};