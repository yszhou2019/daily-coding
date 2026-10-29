class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        auto check = [&piles, h](int k) {
            long long total{};
            for (auto p : piles) {
                total += (p + k - 1) / k;
                if (total > h)
                    return false;
            }
            return total <= h;
        };
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