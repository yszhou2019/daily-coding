class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (isOK(nums, k, mid))
                r = mid;
            else
                l = mid + 1;
        }
        if (isOK(nums, k, n))
            return l;
        return -1;
    }

    bool isOK(vector<int>& nums, int k, int len) {
        int n = nums.size();
        vector<int> count(31);

        auto push = [&count](int val) {
            for (int j = 0; j < 31; j++)
                count[j] += (val >> j) & 1;
        };
        auto pop = [&count](int val) {
            for (int j = 0; j < 31; j++)
                count[j] -= (val >> j) & 1;
        };
        auto merge = [&count]() {
            int val{};
            for (int j = 0; j < 31; j++)
                if (count[j] > 0)
                    val |= (1 << j);
            return val;
        };

        for (int i = 0; i < len - 1; i++)
            push(nums[i]);

        for (int i = len - 1; i < n; i++) {
            push(nums[i]);
            if (merge() >= k)
                return true;
            pop(nums[i - len + 1]);
        }
        return false;
    }
};