class Solution {
public:
    using ll = long long;
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        auto check = [=, &time](ll x) {
            ll tot{};
            for (auto t : time)
                tot += x / t;
            return tot >= totalTrips;
        };

        ll l = 1, r = *min_element(time.begin(), time.end()) *
                      static_cast<ll>(totalTrips);
        while (l < r) {
            ll mid = (l + r) / 2;
            if (check(mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};