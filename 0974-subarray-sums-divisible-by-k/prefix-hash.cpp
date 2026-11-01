class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + nums[i];

        int res{};
        unordered_map<int, int> hash{};
        hash[0] = 1;
        auto mod = [k](int x) { return (x % k + k) % k; };
        for (int i = 0; i < n; i++) {
            int m = mod(pre[i]);
            res += hash[m];
            hash[m]++;
        }
        return res;
    }
};