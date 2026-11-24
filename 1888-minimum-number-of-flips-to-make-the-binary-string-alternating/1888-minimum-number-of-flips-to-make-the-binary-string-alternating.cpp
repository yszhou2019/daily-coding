class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        // inclusive, number of flips to make prefix/suffix valid
        vector<int> left0(n), left1(n), right0(n), right1(n);

        for (int i = 0; i < n; i++) {
            left0[i] =
                (i == 0 ? 0 : left0[i - 1]) + ((s[i] == '0') xor (i % 2 == 0));
            left1[i] =
                (i == 0 ? 0 : left1[i - 1]) + ((s[i] == '1') xor (i % 2 == 0));
        }

        for (int i = n - 1; i >= 0; i--) {
            right0[i] = (i == n - 1 ? 0 : right0[i + 1]) +
                        ((s[i] == '0') xor ((n - 1 - i) % 2 == 0));
            right1[i] = (i == n - 1 ? 0 : right1[i + 1]) +
                        ((s[i] == '1') xor ((n - 1 - i) % 2 == 0));
        }

        int res{INT_MAX};
        res = min(res, left0[n - 1]);
        res = min(res, left1[n - 1]);
        res = min(res, right0[0]);
        res = min(res, right1[0]);
        for (int i = 0; i < n - 1; i++) {
            res = min(res, left0[i] + right1[i + 1]);
            res = min(res, left1[i] + right0[i + 1]);
        }
        return res;
    }
};