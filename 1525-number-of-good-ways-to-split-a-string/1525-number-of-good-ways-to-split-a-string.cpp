class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> left(n), right(n); // number of how many kinds of char
        vector<int> count(26);         // count of each char

        int sum{};
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            count[idx]++;
            if (count[idx] == 1)
                sum++;
            left[i] = sum;
        }

        sum = 0;
        count.assign(26, 0);
        for (int i = n - 1; i >= 0; i--) {
            int idx = s[i] - 'a';
            count[idx]++;
            if (count[idx] == 1)
                sum++;
            right[i] = sum;
        }

        int res{};
        for (int i = 0; i < n - 1; i++)
            if (left[i] == right[i + 1])
                res++;
        return res;
    }
};