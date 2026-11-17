class Solution {
public:
    using ll = long long;
    using pii = pair<int, int>;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for (int i = 0; i < n; i++)
            tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());

        ll cur{};
        vector<int> res{};
        // store executable tasks
        priority_queue<pii, vector<pii>, greater<>> pq{};
        for (int i = 0; i < n; i++) {
            // consume
            while (!pq.empty() && cur < tasks[i][0]) {
                auto [dura, idx] = pq.top();
                cur += dura;
                res.push_back(idx);
                pq.pop();
            }
            // enqueue
            pq.push({tasks[i][1], tasks[i][2]});
            // wait
            cur = max(cur, (ll)tasks[i][0]);
        }
        while (!pq.empty()) {
            auto [dura, idx] = pq.top();
            cur += dura;
            res.push_back(idx);
            pq.pop();
        }
        return res;
    }
};