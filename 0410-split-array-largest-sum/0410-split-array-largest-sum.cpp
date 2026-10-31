class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        auto check = [=, &nums](int x) {
            int cur{nums[0]}, cnt{1};
            for (int i = 1; i < n; i++) {
                if (x - cur >= nums[i]) {
                    cur += nums[i];
                } else {
                    cur = nums[i];
                    cnt++;
                }
            }
            return cnt <= k;
        };

        int l = *max_element(nums.begin(), nums.end()), r = n * 1e6;
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