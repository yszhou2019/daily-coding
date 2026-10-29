class Solution {
public:
    using PII = pair<int, int>;
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<PII> records{};
        for (int i = 0; i < intervals.size(); i++)
            records.push_back({intervals[i][0], i});
        sort(records.begin(), records.end());

        vector<int> res{};
        for (auto& p : intervals) {
            auto it = lower_bound(records.begin(), records.end(),
                                  make_pair(p[1], INT_MIN));
            if (it == records.end())
                res.push_back(-1);
            else
                res.push_back(it->second);
        }
        return res;
    }
};