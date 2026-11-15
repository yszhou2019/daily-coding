class Solution {
public:
    using pii = pair<int, int>;
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage,
                                int k) {
        int n = quality.size();
        vector<pii> workers{};
        for (int i = 0; i < n; i++)
            workers.push_back({quality[i], wage[i]});

        // sort by unit cost
        sort(workers.begin(), workers.end(), [](auto& a, auto& b) {
            return a.second * b.first < b.second * a.first;
        });

        // store dynamic quality
        priority_queue<int> pq{};
        int sum{}; // sum of quality
        double res = numeric_limits<double>::max();
        for (auto [q, w] : workers) {
            if (pq.size() < k) {
                pq.push(q);
                sum += q;
            } else if (pq.size() == k && pq.top() > q) {
                sum -= pq.top();
                pq.pop();
                sum += q;
                pq.push(q);
            }

            if (pq.size() == k)
                res = min(res, double(w) / q * sum);
        }
        return res;
    }
};