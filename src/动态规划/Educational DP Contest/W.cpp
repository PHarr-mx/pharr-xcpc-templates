#include<bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;

#define int i64

using vi = vector<int>;

struct Node {
    int l, r, val, tag;
    Node *left, *right;

    Node(int l, int r, int val, int tag, Node *left, Node *right)
            : l(l), r(r), val(val), tag(tag), left(left), right(right) {};
} *root;

Node *build(int l, int r) {
    if (l == r) return new Node(l, r, 0, 0, nullptr, nullptr);
    int mid = (l + r) / 2;
    Node *left = build(l, mid), *right = build(mid + 1, r);
    return new Node(l, r, 0, 0, left, right);
}

void mark(int v, Node *cur) {
    if (cur == nullptr) return;
    cur->val += v, cur->tag += v;
    return;
}

void pushdown(Node *cur) {
    if (cur->tag == 0) return;
    mark(cur->tag, cur->left), mark(cur->tag, cur->right);
    cur->tag = 0;
    return;
}

void modify(int l, int r, int v, Node *cur) {
    if (l > cur->r or r < cur->l) return;
    if (l <= cur->l and cur->r <= r) {
        mark(v, cur);
        return;
    }
    pushdown(cur);
    int mid = (cur->l + cur->r) / 2;
    if (l <= mid) modify(l, r, v, cur->left);
    if (r > mid) modify(l, r, v, cur->right);
    cur->val = max(cur->left->val, cur->right->val);
}


i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> a(m);
    for (auto &[l, r, v]: a)
        cin >> l >> r >> v;
    sort(a.begin(), a.end(), [&](const auto &x, const auto &y) {
        return x[1] < y[1];
    });
    root = build(1, n);
    for (int i = 1, p = 0; i <= n; i++) {
        modify(i, i, root->val, root);
        for (; p < m and a[p][1] == i; p++)
            modify(a[p][0], i, a[p][2], root);
    }
    cout << max(0ll, root->val);
    return 0;
}