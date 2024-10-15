// luogu P3834
#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;

#define int i64

using vi = vector<int>;

const i32 inf = INT_MAX / 2;

struct Node {
    int l, r, val;
    Node *left, *right;

    Node(int p) : l(p), r(p) {
        val = 0;
        left = right = nullptr;
    }

    Node(int l, int r, Node *left, Node *right)
            : l(l), r(r), left(left), right(right) {
        val = left->val + right->val;
    }

    Node(int l, int r) : l(l), r(r) {
        val = 0;
        left = right = nullptr;
    }
};


Node *build(int l, int r) {
    if (l == r) return new Node(l);
    int mid = (l + r) / 2;
    auto left = build(l, mid);
    auto right = build(mid + 1, r);
    return new Node(l, r, left, right);
}

Node *update(Node *last, int pos, int val) {
    Node *now = new Node(last->l, last->r);
    if (now->l == now->r) {
        now->val = last->val + val;
        return now;
    }
    int mid = (now->l + now->r) / 2;
    if (pos <= mid) {
        now->right = last->right;
        now->left = update(last->left, pos, val);
    } else {
        now->left = last->left;
        now->right = update(last->right, pos, val);
    }
    now->val = now->left->val + now->right->val;
    return now;
}

int query(const Node *last, const Node *now, int k) {
    if (now->l == now->r) return now->l;
    int val = now->left->val - last->left->val;
    if (val < k) return query(last->right, now->right, k - val);
    else return query(last->left, now->left, k);
}

void debug(const Node *root, int dep = 0) {
    for (int i = 0; i < dep; i++) cerr << "  ";
    cerr << root->l << " , " << root->r << " = " << root->val << "\n";
    if (root->left != nullptr) {
        debug(root->left, dep + 1);
        debug(root->right, dep + 1);
    }
    return;
}

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, q;
    cin >> n >> q;

    vi a(n);
    for (auto &ai: a) cin >> ai;

    auto b = a;
    ranges::sort(b);
    b.erase(ranges::unique(b).begin(), b.end());
    int len = b.size() - 1;
    vector<Node *> root(n + 1);
    root[0] = build(0, len);

    auto getP = [b](int x) {
        return ranges::lower_bound(b, x) - b.begin();
    };

    for (int i = 1; i <= n; i++)
        root[i] = update(root[i - 1], getP(a[i - 1]), 1);

    for (int l, r, k; q; q--) {
        cin >> l >> r >> k;
        cout << b[query(root[l - 1], root[r], k)] << "\n";
    }
    return 0;
}