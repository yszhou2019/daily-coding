/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
    using PII = pair<int, int>;
    set<vector<int>> ans;

public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        dfs(customfunction, z, 1, 1000, 1, 1000);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }

private:
    void dfs(CustomFunction& func, int z, int x1, int x2, int y1, int y2) {
        if (x1 > x2 || y1 > y2)
            return;
        if (x1 == x2 && y1 == y2) {
            int val = func.f(x1, y1);
            if (val == z)
                ans.insert({x1, y1});
            return;
        }
        int x = (x1 + x2) / 2;
        int y = (y1 + y2) / 2;
        int val = func.f(x, y);
        if (val == z) {
            ans.insert({x, y});
            dfs(func, z, x + 1, x2, y1, y - 1);
            dfs(func, z, x1, x - 1, y + 1, y2);
        } else if (val < z) {
            dfs(func, z, x + 1, x2, y1, y2);
            dfs(func, z, x1, x2, y + 1, y2);
        } else {
            dfs(func, z, x1, x - 1, y1, y2);
            dfs(func, z, x1, x2, y1, y - 1);
        }
    }
};