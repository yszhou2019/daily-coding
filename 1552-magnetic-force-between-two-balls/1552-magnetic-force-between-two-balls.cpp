class Solution {
public:
    using ll = long long;
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        auto check = [=, &position](ll x) {
            int cnt{1}, last{position[0]};
            for (int i = 1; i < n; i++) {
                if (position[i] - last >= x) {
                    cnt++;
                    last = position[i];
                }
            }
            return cnt >= m;
        };

        ll l = 1, r = position.back();
        while (l < r) {
            ll mid = r - (r - l) / 2;
            if (check(mid))
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};