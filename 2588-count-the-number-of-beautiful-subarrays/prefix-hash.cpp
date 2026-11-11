class Solution {
public:
    using ll = long long;
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] xor nums[i];

        unordered_map<int, int> hash{}; // prefix XOR, count
        hash[0] = 1;
        ll res{};
        for (int i = 0; i < n; i++) {
            if (auto it = hash.find(pre[i]); it != hash.end())
                res += it->second;
            hash[pre[i]]++;
        }
        return res;
    }
};