class Solution {
public:
    using ll = long long;
    bool isPerfectSquare(int num) {
        ll l = 1, r = num;
        while (l <= r) {
            ll mid = (l + r) / 2;
            ll val = mid * mid;
            if (val == num)
                return true;
            if (val > num)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
};