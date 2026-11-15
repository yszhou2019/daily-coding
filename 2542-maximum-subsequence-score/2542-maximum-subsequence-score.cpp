class Solution {
public:
    using ll = long long;
    using pii = pair<int, int>;
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pii> workers{};
        for (int i = 0; i < n; i++)
            workers.push_back({nums1[i], nums2[i]});

        sort(workers.begin(), workers.end(),
             [](auto& a, auto& b) { return a.second > b.second; });

        ll res{}, sum{};
        priority_queue<int, vector<int>, greater<>> pq{};
        for (auto [n1, n2] : workers) {
            if (pq.size() < k) {
                sum += n1;
                pq.push(n1);
            } else if (pq.size() == k && pq.top() < n1) {
                sum -= pq.top();
                sum += n1;
                pq.pop();
                pq.push(n1);
            }

            if (pq.size() == k)
                res = max(res, sum * n2);
        }
        return res;
    }
};