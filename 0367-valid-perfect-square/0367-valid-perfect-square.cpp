class Solution {
public:
    using LL = long long;
    bool isPerfectSquare(int num) {
        LL l = 1, r = num;
        while (l <= r) {
            LL mid = l + (r - l) / 2;
            LL val = mid * mid;
            if (val == num)
                return true;
            if (val < num)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
};