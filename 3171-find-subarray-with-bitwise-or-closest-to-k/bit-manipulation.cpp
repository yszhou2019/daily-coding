class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        unordered_set<int> Set{}, prev{};
        int res{INT_MAX};
        for (auto num : nums) {
            for (auto x : prev)
                Set.insert(x | num);
            Set.insert(num);

            for (auto x : Set)
                res = min(res, abs(x - k));

            prev = Set;
            Set.clear();
        }
        return res;
    }
};