class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 0);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + nums[i];

        unordered_map<int, int> hash{};
        int res{};
        hash[0] = -1;
        for (int r = 0; r < n; r++) {
            int diff = 2 * pre[r] - r - 1; // count of ones - count of zeros
            if (auto it = hash.find(diff); it != hash.end()) {
                res = max(res, r - it->second);
            } else {
                hash[diff] = r;
            }
        }
        return res;
    }
};