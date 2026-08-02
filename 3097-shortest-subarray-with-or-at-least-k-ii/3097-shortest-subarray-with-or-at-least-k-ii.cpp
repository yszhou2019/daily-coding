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
            node->info = nums[a];
            return;
        }
        int mid = (a + b) / 2;
        node->left = new SegTreeNode(a, mid);
        node->right = new SegTreeNode(mid + 1, b);
        init(node->left, a, mid);
        init(node->right, mid + 1, b);
        node->info = node->left->info | node->right->info;
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
        node->info = node->left->info | node->right->info;
    }

    int query(SegTreeNode* node, int a, int b) {
        if (b < node->start || a > node->end)
            return 0;
        if (a <= node->start && node->end <= b)
            return node->info;
        return query(node->left, a, b) | query(node->right, a, b);
    }

    SegTreeNode* root;
    vector<int> nums;
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        SegTreeNode* root = new SegTreeNode(0, n - 1);
        this->nums = nums;
        init(root, 0, n - 1);

        int res{INT_MAX};
        for (int i = 0; i < n; i++) {
            int l = i, r = n - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (query(root, i, mid) >= k)
                    r = mid;
                else
                    l = mid + 1;
            }
            if (query(root, i, n - 1) >= k)
                res = min(res, l - i + 1);
        }
        return res == INT_MAX ? -1 : res;
    }
};