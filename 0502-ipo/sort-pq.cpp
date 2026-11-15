class Solution {
public:
    using pii = pair<int, int>;
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        vector<pii> items{};
        int n = profits.size();
        for (int i = 0; i < n; i++)
            items.push_back({capital[i], profits[i]});
        sort(items.begin(), items.end(),
             [](auto& a, auto& b) { return a.first < b.first; });

        priority_queue<int> pq{};
        int i{}, cnt{};
        while (cnt < k) {
            // enqueue
            while (i < n && w >= items[i].first) {
                pq.push(items[i].second);
                i++;
            }

            // pick up the best and do
            if (pq.empty())
                break;
            w += pq.top();
            pq.pop();

            // next round
            cnt++;
        }

        return w;
    }
};