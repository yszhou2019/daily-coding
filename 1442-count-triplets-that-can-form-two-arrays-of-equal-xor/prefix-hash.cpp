class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre(n);
        pre[0] = arr[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] xor arr[i];

        unordered_multimap<int, int> hash{}; // prefix xor -> right index
        hash.insert({0, -1});
        int res{};
        for (int i = 0; i < n; i++) {
            auto range = hash.equal_range(pre[i]);
            for (auto it = range.first; it != range.second; it++)
                res += max(0, i - it->second - 1);
            hash.insert({pre[i], i});
        }
        return res;
    }
};