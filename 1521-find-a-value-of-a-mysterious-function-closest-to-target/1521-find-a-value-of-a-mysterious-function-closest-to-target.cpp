class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        unordered_set<int> Set{}, prev{};
        int res{INT_MAX};
        for (auto num : arr) {
            for (auto x : prev)
                Set.insert(x & num);
            Set.insert(num);

            for (auto x : Set)
                res = min(res, abs(x - target));

            prev = Set;
            Set.clear();
        }
        return res;
    }
};