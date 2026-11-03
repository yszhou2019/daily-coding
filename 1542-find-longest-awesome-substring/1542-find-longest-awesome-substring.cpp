class Solution {
public:
    int longestAwesome(string s) {
        int n = s.size();
        vector<int> pre(n);
        pre[0] = 1 << (s[0] - '0');
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] xor (1 << (s[i] - '0'));
        // bit representation

        vector<int> target{0};
        for (int i = 0; i < 10; i++)
            target.push_back(1 << i);

        int res{0};
        // hash, record prefix bit representation -> the first right index
        unordered_map<int, int> hash{};
        hash[0] = -1;
        for (int i = 0; i < n; i++) {
            for (auto t : target)
                if (auto it = hash.find(t xor pre[i]); it != hash.end())
                    res = max(res, i - it->second);
            if (hash.find(pre[i]) == hash.end())
                hash[pre[i]] = i;
        }
        return res;
    }
};