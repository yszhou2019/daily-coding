class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        // each number in nums is distinct, number zero occurs at most once
        transform(nums.begin(), nums.end(), nums.begin(), [k](int n) {
            if (n == k)
                return 0;
            if (n < k)
                return -1;
            return 1;
        });

        // odd / even subarray(starting from 0): prefix sum -> count of such
        // subarrays
        unordered_map<int, int> odd{}, even{};
        even[0] = 1;
        int pre{}, res{};
        for (int i = 0; i < nums.size(); i++) {
            pre += nums[i];
            if (i % 2 == 0) {
                res += even[pre];
                res += odd[pre - 1];
                odd[pre]++;
            } else {
                res += even[pre - 1];
                res += odd[pre];
                even[pre]++;
            }
        }
        return res;
    }
};