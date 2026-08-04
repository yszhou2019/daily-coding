class MajorityChecker {
public:
    class SegTreeNode {
    public:
        int start, end;
        int info, freqdiff;
        SegTreeNode *left, *right;
        SegTreeNode(int s, int e)
            : start(s), end(e), info(0), left(nullptr), right(nullptr) {}
    };
    void init(SegTreeNode* node, int a, int b) {
        if (a == b) {
            node->info = nums[a];
            node->freqdiff = 1;
            return;
        }
        int mid = (a + b) / 2;
        node->left = new SegTreeNode(a, mid);
        node->right = new SegTreeNode(mid + 1, b);
        init(node->left, a, mid);
        init(node->right, mid + 1, b);
        if (node->left->info == node->right->info) {
            node->info = node->left->info;
            node->freqdiff = node->left->freqdiff + node->right->freqdiff;
        } else if (node->left->freqdiff > node->right->freqdiff) {
            node->info = node->left->info;
            node->freqdiff = node->left->freqdiff - node->right->freqdiff;
        } else {
            node->info = node->right->info;
            node->freqdiff = node->right->freqdiff - node->left->freqdiff;
        }
    }

    pair<int, int> query(SegTreeNode* node, int a, int b) {
        if (b < node->start || a > node->end)
            return {0, 0};
        if (a <= node->start && node->end <= b)
            return {node->info, node->freqdiff};
        auto L = query(node->left, a, b);
        auto R = query(node->right, a, b);
        if (L.first == R.first)
            return {L.first, L.second + R.second};
        if (L.second > R.second)
            return {L.first, L.second - R.second};
        return {R.first, R.second - L.second};
    }

    SegTreeNode* root;
    vector<int> nums;
    unordered_map<int, vector<int>> Map;

    MajorityChecker(vector<int>& arr) {
        int n = arr.size();
        this->nums = arr;
        root = new SegTreeNode(0, n - 1);
        init(root, 0, n - 1);
        for (int i = 0; i < n; i++)
            Map[arr[i]].push_back(i);
    }

    int query(int left, int right, int threshold) {
        auto [cand, freqdiff] = query(root, left, right);
        auto l = lower_bound(Map[cand].begin(), Map[cand].end(), left);
        auto r = upper_bound(Map[cand].begin(), Map[cand].end(), right);
        int freq = r - l;
        if (freq >= threshold)
            return cand;
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */