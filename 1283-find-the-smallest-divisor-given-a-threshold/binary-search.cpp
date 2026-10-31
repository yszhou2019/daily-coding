class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        auto check = [=, &nums](int x) {
            int sum{};
            for (auto num : nums)
                sum += (num + x - 1) / x;
            return sum <= threshold;
        };

        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};