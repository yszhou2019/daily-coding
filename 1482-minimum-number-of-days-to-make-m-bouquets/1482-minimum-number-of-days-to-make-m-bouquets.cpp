class Solution {
public:
    using ll = long long;
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < static_cast<ll>(m) * k)
            return -1;

        auto check = [=, &bloomDay](int x) {
            int tot{}, cnt{};
            for (auto b : bloomDay)
                if (b <= x) {
                    cnt++;
                    if (cnt == k) {
                        tot++;
                        cnt = 0;
                    }
                } else {
                    cnt = 0;
                }

            return tot >= m;
        };

        int l = 1, r = 1e9;
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