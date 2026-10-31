class Solution {
public:
    using ll = long long;
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        auto check = [=, &weights](int k) {
            int total{1};
            ll cur{weights[0]};
            for (int i = 1; i < n; i++) {
                if (k - cur >= weights[i])
                    cur += weights[i];
                else {
                    cur = weights[i];
                    total++;
                }
            }
            return total <= days;
        };

        ll l = *max_element(weights.begin(), weights.end()), r = n * 5 * 1e4;
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