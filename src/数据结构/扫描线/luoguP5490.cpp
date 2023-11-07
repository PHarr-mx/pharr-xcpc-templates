// luogu P5490
#include<bits/stdc++.h>

using namespace std;

#define int long long
using vi = vector<int>;

struct Node {
    int l, r, value, cnt; // cnt 指当前区间被覆盖的次数
    Node *left, *right;

    Node(int l, int r, int value, int cnt, Node *left, Node *right)
            : l(l), r(r), value(value), cnt(cnt), left(left), right(right) {};
} *root;


using seg = array<int, 4>;

vi raw; // 指原始坐标

int val(int x) { // x 是原始值，返回哈希值
    int i = lower_bound(raw.begin(), raw.end(), x) - raw.begin();
    if (raw[i] != x) return -1;
    return i;
}


Node *build(int l, int r) {
    if (l == r) return new Node(l, r, 0, 0, nullptr, nullptr);
    int mid = (l + r) / 2;
    auto left = build(l, mid), right = build(mid + 1, r);
    return new Node(l, r, 0, 0, left, right);
}

void pushUp(Node *rt) {
    if (rt->cnt > 0) rt->value = raw[rt->r + 1] - raw[rt->l];
    else if (rt->left == nullptr) rt->value = 0;
    else rt->value = rt->left->value + rt->right->value;
    return;
}

void modify(Node *rt, int l, int r, int v) {
    if (l > rt->r or r < rt->l) return;
    if (l <= rt->l and rt->r <= r) {
        rt->cnt += v;
        pushUp(rt);
        return;
    }
    int mid = (rt->l + rt->r) / 2;
    if (l <= mid) modify(rt->left, l, r, v);
    if (mid < r) modify(rt->right, l, r, v);
    pushUp(rt);
}

int32_t main() {
    ios::sync_with_stdio(false) , cin.tie(nullptr);
    int n;
    cin >> n;
    vector<seg> p;
    for (int i = 1, xa, xb, ya, yb; i <= n; i++) {
        cin >> xa >> ya >> xb >> yb;
        p.push_back(seg{xa, ya, yb, 1});
        p.push_back(seg{xb, ya, yb, -1});
        raw.push_back(ya), raw.push_back(yb);
    }
    sort(p.begin(), p.end());
    sort(raw.begin(), raw.end());
    raw.resize(unique(raw.begin(), raw.end()) - raw.begin());
    int tot = raw.size() - 1;
    root = build(0, tot);
    modify(root, val(p[0][1]), val(p[0][2]) - 1, p[0][3]);
    int res = 0;
    for (int i = 1; i < p.size(); i++) {
        res += (p[i][0] - p[i - 1][0]) * root->value;
        modify(root, val(p[i][1]), val(p[i][2]) - 1, p[i][3]);
    }
    cout << res << "\n";
    return 0;
}