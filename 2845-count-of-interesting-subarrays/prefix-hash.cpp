class Solution {
public:
    using ll = long long;
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<ll> pre(n);
        pre[0] = nums[0] % modulo == k ? 1 : 0;
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + (nums[i] % modulo == k ? 1 : 0);

        // qualified count % mod -> number of such subarray
        unordered_map<int, int> hash{};
        hash[0] = 1;
        ll res{};
        for (int i = 0; i < n; i++) {
            int t = (pre[i] % modulo - k + modulo) % modulo;
            if (auto it = hash.find(t); it != hash.end())
                res += it->second;
            hash[pre[i] % modulo]++;
        }
        return res;
    }
};