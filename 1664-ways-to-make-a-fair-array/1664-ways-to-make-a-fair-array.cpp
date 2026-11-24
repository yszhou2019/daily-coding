class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        // inclusive
        vector<int> leftOdd(n), leftEven(n), rightOdd(n), rightEven(n);

        leftOdd[0] = nums[0];
        for (int i = 1; i < n; i++)
            if (i % 2 == 0) {
                leftOdd[i] = leftOdd[i - 1] + nums[i];
                leftEven[i] = leftEven[i - 1];
            } else {
                leftEven[i] = leftEven[i - 1] + nums[i];
                leftOdd[i] = leftOdd[i - 1];
            }

        if (n % 2 == 0)
            rightEven[n - 1] = nums[n - 1];
        else
            rightOdd[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
            if (i % 2 == 0) {
                rightOdd[i] = rightOdd[i + 1] + nums[i];
                rightEven[i] = rightEven[i + 1];
            } else {
                rightEven[i] = rightEven[i + 1] + nums[i];
                rightOdd[i] = rightOdd[i + 1];
            }

        int res{};
        for (int i = 0; i < n; i++)
            if (leftOdd[i] + rightEven[i] == leftEven[i] + rightOdd[i])
                res++;
        return res;
    }
};