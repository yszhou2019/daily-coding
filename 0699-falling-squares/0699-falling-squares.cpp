
class SegTreeNode {
public:
    int start, end;
    int info; // max height
    int tag;
    SegTreeNode *left, *right;
    SegTreeNode(int a, int b)
        : start(a), end(b), info(0), tag(0), left(nullptr), right(nullptr) {
        init(a, b);
    }

    void updateRange(int a, int b, int h) {
        if (b < start || a > end)
            return;
        if (a <= start && b >= end) {
            info = h;
            tag = 1;
            return;
        }
        pushDown();
        left->updateRange(a, b, h);
        right->updateRange(a, b, h);
        info = max(left->info, right->info);
    }

    int query(int a, int b) {
        if (b < start || a > end)
            return 0;
        if (a <= start && b >= end)
            return info;
        pushDown();
        int l = left->query(a, b);
        int r = right->query(a, b);
        return max(l, r);
    }

private:
    void init(int a, int b) {
        if (a == b)
            return;
        int mid = (a + b) / 2;
        left = new SegTreeNode(a, mid);
        right = new SegTreeNode(mid + 1, b);
        info = max(left->info, right->info);
    }

    void pushDown() {
        if (tag && left) {
            tag = 0;
            left->info = info;
            left->tag = 1;
            right->info = info;
            right->tag = 1;
        }
    }
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        set<int> Set{};
        for (auto& p : positions) {
            Set.insert(p[0]);
            Set.insert(p[0] + p[1]);
        }
        int idx{};
        unordered_map<int, int> pos2idx{};
        for (auto x : Set) {
            pos2idx[x] = idx;
            idx++;
        }

        int n = Set.size();
        auto root = new SegTreeNode(0, n - 1);

        vector<int> res{};
        for (auto& square : positions) {
            int l = pos2idx[square[0]];
            int r = pos2idx[square[0] + square[1]] - 1;
            int h = root->query(l, r);
            root->updateRange(l, r, h + square[1]);
            res.push_back(root->query(0, n - 1));
        }
        return res;
    }
};