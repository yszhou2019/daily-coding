class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();

        priority_queue<int, vector<int>, greater<>> pq{};
        int res{}, i{};
        for (int d = 1; d <= 100'000; d++) {
            // enqueue
            while (i < n && d >= events[i][0]) {
                pq.push(events[i][1]);
                i++;
            }
            // clean expired
            while (!pq.empty() && pq.top() < d)
                pq.pop();
            if (!pq.empty()) {
                pq.pop();
                res++;
            }
        }
        return res;
    }
};