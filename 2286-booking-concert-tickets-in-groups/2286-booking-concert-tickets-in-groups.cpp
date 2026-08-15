using ll = long long;
class SegTreeNode {
private:
    int start, end;
    int info; // max seats in a row
    SegTreeNode *left, *right;

    void init(int a, int b, int val) {
        if (a == b)
            return;
        int mid = (a + b) / 2;
        left = new SegTreeNode(a, mid, val);
        right = new SegTreeNode(mid + 1, b, val);
    }

public:
    SegTreeNode(int a, int b, int val)
        : start(a), end(b), info(val), left(nullptr), right(nullptr) {
        init(a, b, val);
    }

    void update(int a, int b, int val) {
        if (b < start || a > end)
            return;
        if (a <= start && b >= end) {
            info = val;
            return;
        }
        left->update(a, b, val);
        right->update(a, b, val);
        info = max(left->info, right->info);
    }

    int query(int a, int b) {
        if (b < start || a > end)
            return 0;
        if (a <= start && b >= end)
            return info;
        int l = left->query(a, b);
        int r = right->query(a, b);
        return max(l, r);
    }
};

class SegTreeNode2 {
private:
    int start, end;
    ll info; // sum of seats
    SegTreeNode2 *left, *right;

    void init(int a, int b, int val) {
        if (a == b) {
            info = val;
            return;
        }
        int mid = (a + b) / 2;
        left = new SegTreeNode2(a, mid, val);
        right = new SegTreeNode2(mid + 1, b, val);
        info = left->info + right->info;
    }

public:
    SegTreeNode2(int a, int b, int val)
        : start(a), end(b), info(0), left(nullptr), right(nullptr) {
        init(a, b, val);
    }

    void update(int a, int b, int val) {
        if (b < start || a > end)
            return;
        if (a <= start && b >= end) {
            info = val;
            return;
        }
        left->update(a, b, val);
        right->update(a, b, val);
        info = left->info + right->info;
    }

    ll query(int a, int b) {
        if (b < start || a > end)
            return 0;
        if (a <= start && b >= end)
            return info;
        ll l = left->query(a, b);
        ll r = right->query(a, b);
        return l + r;
    }
};

class BookMyShow {
    int n, m, p{};
    vector<int> seats;
    SegTreeNode* root;
    SegTreeNode2* root2;

public:
    BookMyShow(int n, int m) {
        this->n = n;
        this->m = m;

        seats.resize(n);
        for (int i = 0; i < n; i++)
            seats[i] = m;

        root = new SegTreeNode(0, n - 1, m);
        root2 = new SegTreeNode2(0, n - 1, m);
    }

    vector<int> gather(int k, int maxRow) {
        int l = 0, r = maxRow;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (root->query(0, mid) >= k)
                r = mid;
            else
                l = mid + 1;
        }
        if (root->query(l, l) < k)
            return {};

        seats[l] -= k;
        root->update(l, l, seats[l]);
        root2->update(l, l, seats[l]);

        return {l, m - (seats[l] + k)};
    }

    bool scatter(int k, int maxRow) {
        if (root2->query(0, maxRow) < k)
            return false;

        while (k > 0) {
            int t = min(k, seats[p]);
            seats[p] -= t;
            root->update(p, p, seats[p]);
            root2->update(p, p, seats[p]);
            k -= t;
            if (seats[p] == 0)
                p++;
        }
        return true;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */