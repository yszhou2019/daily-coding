class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> pre(n); // inclusive, ...a (ends with a or empty)
        vector<int> suf(n); // inclusive, b... (starts with b or empty)

        for (int i = 0; i < n; i++)
            pre[i] = (i == 0 ? 0 : pre[i - 1]) + (s[i] == 'b');
        for (int i = n - 1; i >= 0; i--)
            suf[i] = (i == n - 1 ? 0 : suf[i + 1]) + (s[i] == 'a');

        int res{INT_MAX};
        for (int i = 0; i < n - 1; i++)
            res = min(res, pre[i] + suf[i + 1]);
        // two corner cases
        res = min(res, pre[n - 1]);
        res = min(res, suf[0]);
        return res;
    }
};