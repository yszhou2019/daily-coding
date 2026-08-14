class Solution {
public:
    using ll = long long;

    class SegTreeNode {
    public:
        int start, end;
        ll info;
        int flip;
        SegTreeNode *left, *right;
        SegTreeNode(int a, int b, vector<int>& nums)
            : start(a), end(b), info(0), flip(0), left(nullptr),
              right(nullptr) {
            init(a, b, nums);
        }

        void updateRangeby(int a, int b) {
            if (b < start || a > end)
                return;
            if (a <= start && b >= end) {
                info = end - start + 1 - info;
                flip = 1 - flip;
                return;
            }
            pushDown();
            left->updateRangeby(a, b);
            right->updateRangeby(a, b);
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
        void init(int a, int b, vector<int>& nums) {
            if (a == b) {
                info = nums[a];
                return;
            }
            int mid = (a + b) / 2;
            left = new SegTreeNode(a, mid, nums);
            right = new SegTreeNode(mid + 1, b, nums);
            info = left->info + right->info; // update from bottom up
        }

        void pushDown() {
            if (flip && left) {
                left->info = left->end - left->start + 1 - left->info;
                left->flip = 1 - left->flip;
                right->info = right->end - right->start + 1 - right->info;
                right->flip = 1 - right->flip;
                flip = 0;
            }
        }
    };

    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2,
                                  vector<vector<int>>& queries) {
        ll sum{accumulate(nums2.begin(), nums2.end(), 0LL)};
        int n = nums1.size();
        auto root = new SegTreeNode(0, n - 1, nums1);

        vector<ll> res{};
        for (auto& q : queries) {
            if (q[0] == 1)
                root->updateRangeby(q[1], q[2]);
            else if (q[0] == 2)
                sum += root->query(0, n - 1) * q[1];
            else
                res.push_back(sum);
        }
        return res;
    }
};