class Solution {
public:
    class SegTreeNode {
    public:
        int start, end;
        int info;
        SegTreeNode *left, *right;
        SegTreeNode(int s, int e)
            : start(s), end(e), info(0), left(nullptr), right(nullptr) {}
    };
    void init(SegTreeNode* node, int a, int b) {
        if (a == b) {
            node->info = peak[a];
            return;
        }
        int mid = (a + b) / 2;
        node->left = new SegTreeNode(a, mid);
        node->right = new SegTreeNode(mid + 1, b);
        init(node->left, a, mid);
        init(node->right, mid + 1, b);
        node->info = node->left->info + node->right->info;
    }

    void updateTree(SegTreeNode* node, int idx, int info) {
        if (idx < node->start || idx > node->end)
            return;
        if (node->start == node->end) {
            node->info = info;
            return;
        }
        updateTree(node->left, idx, info);
        updateTree(node->right, idx, info);
        node->info = node->left->info + node->right->info;
    }

    int query(SegTreeNode* node, int a, int b) {
        if (b < node->start || a > node->end)
            return 0;
        if (a <= node->start && node->end <= b)
            return node->info;
        return query(node->left, a, b) + query(node->right, a, b);
    }

    SegTreeNode* root;
    vector<int> peak;

    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> peak(n, 0);
        for (int i = 1; i < n - 1; i++)
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                peak[i] = 1;

        SegTreeNode* root = new SegTreeNode(0, n - 1);
        this->peak = peak;
        init(root, 0, n - 1);

        vector<int> res{};
        auto check = [=, &peak, &nums](int idx) {
            int val = nums[idx] > nums[idx - 1] && nums[idx] > nums[idx + 1];
            if (val == peak[idx])
                return;
            peak[idx] = val;
            updateTree(root, idx, val);
        };
        for (auto q : queries) {
            if (q[0] == 2) {
                int i = q[1];
                int val = q[2];
                nums[i] = val;
                if (i > 0 && i < n - 1)
                    check(i);
                if (i + 1 > 0 && i + 1 < n - 1)
                    check(i + 1);
                if (i - 1 > 0 && i - 1 < n - 1)
                    check(i - 1);
            } else {
                res.push_back(query(root, q[1] + 1, q[2] - 1));
            }
        }

        return res;
    }
};