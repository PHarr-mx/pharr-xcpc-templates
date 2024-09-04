#include<bits/stdc++.h>

using namespace std;


using i32 = int32_t;
using i64 = long long;

struct Info {
    i64 L, O, LO, OL, LOL, OLO;

    Info() {
        L = O = LO = OL = LOL = OLO = 0;
    }

    Info(char c) {
        L = O = LO = OL = LOL = OLO = 0;
        if (c == 'L') L++;
        else O++;
    }

    Info operator+(const Info &b) {
        Info res;
        res.L = L + b.L;
        res.O = O + b.O;
        res.LO = LO + b.LO + L * b.O;
        res.OL = OL + b.OL + O * b.L;
        res.LOL = LOL + b.LOL + L * b.OL + LO * b.L;
        res.OLO = OLO + b.OLO + O * b.LO + OL * b.O;
        return res;
    }

    void swap() {
        std::swap(L, O);
        std::swap(LO, OL);
        std::swap(LOL, OLO);
    }

    i64 val() {
        return LOL;
    }
};

struct Node {
    i32 l, r, tag;
    Info info;

    Node *left, *right;

    Node() {}

    Node(int p, char c) : info(c) {
        l = r = p, tag = 0, left = right = nullptr;
    }

    Node(int l, int r, Node *left, Node *right)
            : l(l), r(r), left(left), right(right) {
        tag = 0, info = left->info + right->info;
    }
};


void maintain(Node *cur) {
    if (cur->left == nullptr) return;
    cur->info = cur->left->info + cur->right->info;
    return;
}

void mark(Node *cur) {
    cur->tag ^= 1;
    cur->info.swap();
    return;
}

void pushdown(Node *cur) {
    if (cur->tag == 0) return;
    if (cur->left != nullptr) {
        mark(cur->left), mark(cur->right);
    }
    cur->tag = 0;
    return;
}

Node *build(i32 l, i32 r, const string &s) {
    if (l == r) return new Node(l, s[l - 1]);
    i32 mid = (l + r) / 2;
    auto left = build(l, mid, s), right = build(mid + 1, r, s);
    return new Node(l, r, left, right);
}

Info query(i32 l, i32 r, Node *cur) {
    if (cur == nullptr) return Info();
    if (l > cur->r or r < cur->l) return Info();
    if (l <= cur->l and cur->r <= r) return cur->info;
    pushdown(cur);
    return query(l, r, cur->left) + query(l, r, cur->right);
}

void modify(i32 l, i32 r, Node *cur) {
    if (cur == nullptr) return;
    if (l > cur->r or r < cur->l) return;
    if (l <= cur->l and cur->r <= r) {
        mark(cur);
        return;
    }
    pushdown(cur);
    modify(l, r, cur->left), modify(l, r, cur->right);
    maintain(cur);
}


i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    auto root = build(1, n, s);
    for (int op, l, r; m; m--) {
        cin >> op >> l >> r;
        if (op == 1) cout << query(l, r, root).val() << "\n";
        else modify(l, r, root);
    }
    return 0;
}