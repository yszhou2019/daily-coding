class Solution {
public:
    using ll = long long;

    class SegTreeNode {
    public:
        int start, end;
        ll info, delta;
        int tag;
        SegTreeNode *left, *right;
        SegTreeNode(int a, int b)
            : start(a), end(b), info(0), delta(0), tag(0), left(nullptr),
              right(nullptr) {
            init(a, b);
        }

        void updateRangeby(int a, int b, int val) {
            if (b < start || a > end)
                return;
            if (a <= start && b >= end) {
                info += (end - start + 1) * val;
                delta += val;
                tag = 1;
                return;
            }
            pushDown();
            left->updateRangeby(a, b, delta + val);
            right->updateRangeby(a, b, delta + val);
            info = left->info + right->info;
        }

        ll query(int a, int b) {
            if (b < start || a > end)
                return 0;
            if (a <= start && b >= end)
                return info;
            pushDown();
            auto l = left->query(a, b);
            auto r = right->query(a, b);
            return l + r;
        }

    private:
        void init(int a, int b) {
            if (a == b)
                return;
            int mid = (a + b) / 2;
            left = new SegTreeNode(a, mid);
            right = new SegTreeNode(mid + 1, b);
        }

        void pushDown() {
            if (tag && left) {
                left->info += (left->end - left->start + 1) * delta;
                left->delta += delta;
                left->tag = 1;
                right->info += (right->end - right->start + 1) * delta;
                right->delta += delta;
                right->tag = 1;
                tag = 0;
                delta = 0;
            }
        }
    };

    const int M = 1e9 + 7;
    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> Map{};
        vector<int> prev(n, -1);
        for (int i = 0; i < n; i++) {
            if (Map.find(nums[i]) != Map.end())
                prev[i] = Map[nums[i]];
            Map[nums[i]] = i;
        }

        auto root = new SegTreeNode(0, n - 1);
        vector<ll> dp(n, 0);
        for (int i = 0; i < n; i++) {
            int j = prev[i];
            dp[i] = (i == 0 ? 0 : dp[i - 1]);
            dp[i] += 2 * root->query(j + 1, i - 1) + i - j - 1;
            dp[i] += 1;
            root->updateRangeby(j + 1, i, 1);
        }

        ll res{};
        for (auto val : dp)
            res = (res + val) % M;
        return res;
    }
};