class Solution {
public:
    using PII = pair<int, int>;
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int, vector<PII>> Map{};
        for (auto& b : buildings) {
            Map[b[0]].push_back({b[2], 1});
            Map[b[1]].push_back({b[2], -1});
        }

        multiset<int> ms{};
        vector<vector<int>> res{};
        for (auto& [pos, pairs] : Map) {
            for (auto [h, flag] : pairs) {
                if (flag == 1)
                    ms.insert(h);
                else
                    ms.erase(ms.find(h));
            }

            int H = ms.empty() ? 0 : *ms.rbegin();
            if (res.empty() || H != res.back()[1])
                res.push_back({pos, H});
        }

        return res;
    }
};