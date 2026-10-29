class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto first = lower_bound(nums.begin(), nums.end(), target);
        auto last = upper_bound(nums.begin(), nums.end(), target);
        if (first != nums.end() && *first == target)
            return {static_cast<int>(first - nums.begin()),
                    static_cast<int>(last - nums.begin() - 1)};
        return {-1, -1};
    }
};