// luogu P5490
#include<bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = long long;
#define int i64
using seg = array<int, 4>; // {x, y1, y2, v}
using vi = vector<int>;

struct Node {
    int l, r, value, cnt;// value 被覆盖子区间长度，cnt 当前区间被完整覆盖的次数。
    Node *left, *right;

    Node(int l, int r, int value, int cnt, Node *left, Node *right)
            : l(l), r(r), value(value), cnt(cnt), left(left), right(right) {};
} *root;

vi raw;// 原始坐标

int val(int x) { // // x 是原始值，返回哈希值
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

void maintain(Node *cur) {
    if (cur->cnt > 0) cur->value = raw[cur->r + 1] - raw[cur->l];
    else if (cur->left == nullptr) cur->value = 0;
    else cur->value = cur->left->value + cur->right->value;
    return;
}

void modify(int l, int r, int v, Node *cur) {
    if (l > cur->r or r < cur->l) return;
    if (l <= cur->l and cur->r <= r) {
        cur->cnt += v;
        maintain(cur);
        return;
    }
    int mid = (cur->l + cur->r) / 2;
    if (l <= mid) modify(l, r, v, cur->left);
    if (r > mid) modify(l, r, v, cur->right);
    maintain(cur);
    return;
}

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
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
    modify(val(p[0][1]), val(p[0][2]) - 1, p[0][3], root);
    int res = 0;
    for (int i = 1; i < p.size(); i++) {
        res += (p[i][0] - p[i - 1][0]) * root->value;
        modify(val(p[i][1]), val(p[i][2]) - 1, p[i][3], root);
    }
    cout << res;
    return 0;
}