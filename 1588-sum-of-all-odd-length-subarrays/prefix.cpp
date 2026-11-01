class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre(n, 0);
        for (int i = 0; i < n; i++)
            pre[i] = (i == 0 ? 0 : pre[i - 1]) + arr[i];

        int sum{};
        for (int len = 1; len <= n; len += 2) {
            for (int i = 0; i + len - 1 < n; i++)
                sum += pre[i + len - 1] - (i == 0 ? 0 : pre[i - 1]);
        }
        return sum;
    }
};