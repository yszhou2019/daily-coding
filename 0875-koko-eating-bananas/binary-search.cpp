class Solution {
public:
    using ll = long long;
    int minEatingSpeed(vector<int>& piles, int h) {
        auto check = [=, &piles](int k) {
            ll total{};
            for (auto p : piles) {
                total += (p + k - 1) / k;
                if (total > h)
                    return false;
            }
            return total <= h;
        };

        int l = 1, r = *max_element(piles.begin(), piles.end());
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