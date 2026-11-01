class Solution {
public:
    const int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre(n);
        pre[0] = arr[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + arr[i];

        int res{};
        unordered_map<int, int> hash{};
        hash[0] = 1;
        for (int i = 0; i < n; i++) {
            res = (res + hash[1 - pre[i] % 2]) % mod;
            hash[pre[i] % 2]++;
        }
        return res;
    }
};