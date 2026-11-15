class Solution {
public:
    using pii = pair<int, int>;

    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        vector<pii> prjs{};
        int n = profits.size();
        for (int i = 0; i < n; i++)
            prjs.push_back({capital[i], profits[i]});
        sort(prjs.begin(), prjs.end());

        priority_queue<int> pq{};
        int i{}, cnt{};
        while (cnt < k) {
            // enqueue
            while (i < n && w >= prjs[i].first) {
                pq.push(prjs[i].second);
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