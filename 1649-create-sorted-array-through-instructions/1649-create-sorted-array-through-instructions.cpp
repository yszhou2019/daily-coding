class Solution {
public:
    class SegTreeNode {
    public:
        SegTreeNode* left;
        SegTreeNode* right;
        int start, end;
        int info;
        SegTreeNode(int a, int b)
            : start(a), end(b), info(0), left(NULL), right(NULL) {}
    };

    void init(SegTreeNode* node, int a, int b) {
        if (a == b) {
            node->info = 0;
            return;
        }
        int mid = (a + b) / 2;
        node->left = new SegTreeNode(a, mid);
        node->right = new SegTreeNode(mid + 1, b);
        init(node->left, a, mid);
        init(node->right, mid + 1, b);
    }

    void updateSingle(SegTreeNode* node, int idx) {
        if (idx < node->start || idx > node->end)
            return;
        if (node->start == node->end) {
            node->info += 1;
            return;
        }
        updateSingle(node->left, idx);
        updateSingle(node->right, idx);
        // update info
        node->info = node->left->info + node->right->info;
    }

    int queryCount(SegTreeNode* node, int a, int b) {
        if (a > node->end || b < node->start)
            return 0;
        if (a <= node->start && b >= node->end)
            return node->info;
        return queryCount(node->left, a, b) + queryCount(node->right, a, b);
    }

    const int M = 1e9 + 7;
    int createSortedArray(vector<int>& instructions) {
        set<int> Set(instructions.begin(), instructions.end());
        unordered_map<int, int> num2idx{};
        int idx{};
        for (auto num : Set) {
            num2idx[num] = idx;
            idx++;
        }

        int n = Set.size();
        SegTreeNode* root = new SegTreeNode(0, n - 1);
        init(root, 0, n - 1);
        int res{};
        for (auto x : instructions) {
            int l = queryCount(root, 0, num2idx[x] - 1);
            int r = queryCount(root, num2idx[x] + 1, n - 1);
            res += min(l, r);
            res %= M;
            updateSingle(root, num2idx[x]);
        }
        return res;
    }
};