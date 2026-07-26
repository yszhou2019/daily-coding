class Solution {
public:
    class SegTreeNode {
    public:
        SegTreeNode* left;
        SegTreeNode* right;
        int start, end;
        int info, pos;
        SegTreeNode(int a, int b)
            : start(a), end(b), info(0), pos(0), left(NULL), right(NULL) {}
    };

    void init(SegTreeNode* node, int a, int b) {
        if (a == b) {
            node->info = target[a];
            node->pos = a;
            return;
        }
        int mid = (a + b) / 2;
        node->left = new SegTreeNode(a, mid);
        node->right = new SegTreeNode(mid + 1, b);
        init(node->left, a, mid);
        init(node->right, mid + 1, b);

        if (node->left->info > node->right->info) {
            node->info = node->right->info;
            node->pos = node->right->pos;
        } else {
            node->info = node->left->info;
            node->pos = node->left->pos;
        }
    }

    pair<int, int> queryRangeMin(SegTreeNode* node, int a, int b) {
        if (a > node->end || b < node->start)
            return {INT_MAX, a};
        if (a <= node->start && node->end <= b)
            return {node->info, node->pos};
        auto L = queryRangeMin(node->left, a, b);
        auto R = queryRangeMin(node->right, a, b);
        if (L.first < R.first)
            return L;
        return R;
    }

    vector<int> target;
    SegTreeNode* root;

    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        this->target = target;
        root = new SegTreeNode(0, n - 1);
        init(root, 0, n - 1);
        return dfs(target, 0, 0, n - 1);
    }

    int dfs(vector<int>& target, int base, int a, int b) {
        if (a > b)
            return 0;
        if (a == b)
            return target[a] - base;
        auto [info, pos] = queryRangeMin(root, a, b);
        int sum = info - base;
        sum += dfs(target, info, a, pos - 1);
        sum += dfs(target, info, pos + 1, b);
        return sum;
    }
};