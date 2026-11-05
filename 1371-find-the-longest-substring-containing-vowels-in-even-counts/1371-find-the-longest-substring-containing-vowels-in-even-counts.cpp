class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> char2num{
            {'a', 1}, {'e', 2}, {'i', 4}, {'o', 8}, {'u', 16}};
        auto convert = [&char2num](char c) {
            if (auto it = char2num.find(c); it != char2num.end())
                return it->second;
            return 0;
        };
        vector<int> pre(n);
        pre[0] = 0 xor convert(s[0]);
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] xor convert(s[i]);

        int res{};
        unordered_map<int, int> hash{};
        hash[0] = -1;
        for (int i = 0; i < n; i++) {
            if (auto it = hash.find(pre[i]); it != hash.end())
                res = max(res, i - it->second);
            else
                hash[pre[i]] = i;
        }
        return res;
    }
};