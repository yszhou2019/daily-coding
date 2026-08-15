
class SegTreeNode {
public:
    int start, end;
    int info, tag;
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
    using PII = pair<int, int>;
    vector<PII> heights;
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        set<int> Set{};
        for (auto& b : buildings) {
            Set.insert(b[0]);
            Set.insert(b[1]);
        }
        int idx{};
        unordered_map<int, int> pos2idx{}, idx2pos{};
        for (auto x : Set) {
            pos2idx[x] = idx;
            idx2pos[idx] = x;
            idx++;
        }

        int n = Set.size();
        auto root = new SegTreeNode(0, n - 1);
        sort(buildings.begin(), buildings.end(),
             [](auto& a, auto& b) { return a[2] < b[2]; });

        for (auto& b : buildings) {
            root->updateRange(pos2idx[b[0]], pos2idx[b[1]] - 1, b[2]);
        }

        DFS(root);

        vector<vector<int>> res{};
        for (int i = 0; i < heights.size(); i++) {
            auto [idx, h] = heights[i];
            res.push_back({idx2pos[idx], h});
            while (i + 1 < heights.size() && h == heights[i + 1].second)
                i++;
        }
        return res;
    }

    void DFS(SegTreeNode* node) {
        if (node->start == node->end || node->tag == 1) {
            heights.push_back({node->start, node->info});
            return;
        }
        DFS(node->left);
        DFS(node->right);
    }
};