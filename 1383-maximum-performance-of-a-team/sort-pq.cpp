class Solution {
public:
    using pii = pair<int, int>;
    using ll = long long;
    const int mod = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency,
                       int k) {
        vector<pii> workers{};
        for (int i = 0; i < n; i++)
            workers.push_back({speed[i], efficiency[i]});
        sort(workers.begin(), workers.end(),
             [](auto& a, auto& b) { return a.second > b.second; });

        priority_queue<int, vector<int>, greater<>> pq{};
        ll sum{}, res{};
        for (auto [s, e] : workers) {
            pq.push(s);
            sum += s;
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            res = max(res, sum * e);
        }
        return res % mod;
    }
};