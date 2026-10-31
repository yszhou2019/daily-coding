class Solution {
public:
    using LL = long long;
    int mySqrt(int x) {
        LL l = 1, r = x;
        while (l <= r) {
            LL mid = l + (r - l) / 2;
            LL val = mid * mid;
            if (val == x)
                return mid;
            if (val > x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l - 1;
    }
};