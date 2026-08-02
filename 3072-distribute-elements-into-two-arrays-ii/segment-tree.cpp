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

    vector<int> resultArray(vector<int>& nums) {
        set<int> Set(nums.begin(), nums.end());
        int n = Set.size();
        int i = 0;
        unordered_map<int, int> num2idx{};
        for (auto num : Set)
            num2idx[num] = i++;

        SegTreeNode* root1 = new SegTreeNode(0, n - 1);
        SegTreeNode* root2 = new SegTreeNode(0, n - 1);
        init(root1, 0, n - 1);
        init(root2, 0, n - 1);
        vector<int> a1{nums[0]}, a2{nums[1]};
        updateSingle(root1, num2idx[nums[0]]);
        updateSingle(root2, num2idx[nums[1]]);

        auto update = [this, &num2idx](vector<int>& arr, SegTreeNode* root,
                                       int val) {
            arr.push_back(val);
            updateSingle(root, num2idx[val]);
        };
        for (i = 2; i < nums.size(); i++) {
            int val = nums[i];
            int q1 = queryCount(root1, num2idx[val] + 1, n - 1);
            int q2 = queryCount(root2, num2idx[val] + 1, n - 1);

            if (q1 > q2)
                update(a1, root1, val);
            else if (q1 < q2)
                update(a2, root2, val);
            else if (a1.size() <= a2.size())
                update(a1, root1, val);
            else
                update(a2, root2, val);
        }

        vector<int> res{a1};
        for (auto num : a2)
            res.push_back(num);
        return res;
    }
};