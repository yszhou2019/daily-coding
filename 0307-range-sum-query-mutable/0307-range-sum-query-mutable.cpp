class NumArray {
public:
    class SegTreeNode {
    public:
        int start, end;
        int val;
        SegTreeNode *left, *right;
        SegTreeNode(int s, int e)
            : start(s), end(e), val(0), left(nullptr), right(nullptr) {}
    };

    SegTreeNode* root;
    vector<int> nums;

    void init(SegTreeNode* node, int a, int b) {
        if (a == b) {
            node->val = nums[a];
            return;
        }
        int mid = (a + b) / 2;
        node->left = new SegTreeNode(a, mid);
        node->right = new SegTreeNode(mid + 1, b);
        init(node->left, a, mid);
        init(node->right, mid + 1, b);
        node->val = node->left->val + node->right->val;
    }

    void updateTree(SegTreeNode* node, int idx, int val) {
        if (idx < node->start || idx > node->end)
            return;
        if (node->start == node->end) {
            node->val = val;
            return;
        }
        updateTree(node->left, idx, val);
        updateTree(node->right, idx, val);
        node->val = node->left->val + node->right->val;
    }

    int query(SegTreeNode* node, int left, int right) {
        if (left <= node->start && node->end <= right)
            return node->val;
        if (right < node->start || left > node->end)
            return 0;
        return query(node->left, left, right) + query(node->right, left, right);
    }

    NumArray(vector<int>& nums) {
        int n = nums.size();
        this->nums = nums;
        root = new SegTreeNode(0, n - 1);
        init(root, 0, n - 1);
    }

    void update(int index, int val) { updateTree(root, index, val); }

    int sumRange(int left, int right) { return query(root, left, right); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */