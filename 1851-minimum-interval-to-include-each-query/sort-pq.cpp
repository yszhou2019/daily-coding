class Solution {
public:
    using pii = pair<int, int>;
    vector<int> minInterval(vector<vector<int>>& intervals,
                            vector<int>& queries) {
        int n = queries.size();
        vector<pii> qs{};
        for (int i = 0; i < n; i++)
            qs.push_back({queries[i], i});
        sort(intervals.begin(), intervals.end());
        sort(qs.begin(), qs.end());

        // (length, right endpoint)
        auto comp = [](auto& a, auto& b) { return a.first > b.first; };
        priority_queue<pii, vector<pii>, decltype(comp)> pq{};
        int i{};
        vector<int> res(n, -1);
        for (auto [q, idx] : qs) {
            // enqueue
            while (i < intervals.size() && intervals[i][0] <= q) {
                pq.push(
                    {intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }
            // dequeue
            while (!pq.empty() && pq.top().second < q)
                pq.pop();
            if (!pq.empty())
                res[idx] = pq.top().first;
        }
        return res;
    }
};