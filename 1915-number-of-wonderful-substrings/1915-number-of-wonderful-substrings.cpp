class Solution {
public:
    using ll = long long;
    long long wonderfulSubstrings(string word) {
        int n = word.size();
        vector<int> pre(n);
        pre[0] = 1 << (word[0] - 'a');
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] xor (1 << (word[i] - 'a'));

        ll res{};
        unordered_map<int, ll> hash{};
        hash[0] = 1;
        vector<int> target{0};
        for (int i = 0; i < 10; i++)
            target.push_back(1 << i);
        for (int i = 0; i < n; i++) {
            for (auto t : target)
                res += hash[pre[i] xor t];
            hash[pre[i]]++;
        }
        return res;
    }
};