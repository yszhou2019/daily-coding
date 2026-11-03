class Solution {
public:
    using ll = long long;
    long long wonderfulSubstrings(string word) {
        int n = word.size();
        vector<int> pre(n); // record count of each char
        pre[0] = 1 << (word[0] - 'a');
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] xor (1 << (word[i] - 'a'));

        vector<int> target{0}; // all possible targets
        for (int i = 0; i < 10; i++)
            target.push_back(1 << i);

        ll res{};
        unordered_map<int, int> hash{}; // pre -> count
        hash[0] = 1;
        for (int i = 0; i < n; i++) {
            for (auto t : target)
                if (auto it = hash.find(t xor pre[i]); it != hash.end())
                    res += it->second;
            hash[pre[i]]++;
        }
        return res;
    }
};