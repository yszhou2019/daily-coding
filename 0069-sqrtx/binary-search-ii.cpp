class Solution {
public:
    using LL = long long;
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        LL l = 1, r = x;
        while (l < r) {
            LL mid = r - (r - l) / 2;
            if (mid * mid > x)
                r = mid - 1;
            else
                l = mid;
        }
        return l;
    }
};