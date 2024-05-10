#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

const int inf = 1e9;

struct Splay {
    int root, tot, n;

    array<int, N> f, val, cnt, size, reverseTag;
    array<array<int, 2>, N> c;

    void updateSize(int p) {
        size[p] = size[c[p][0]] + size[c[p][1]] + cnt[p];
        return;
    }

    bool get(int p) { // 判断 p 是不是父亲的右儿子
        return p == c[f[p]][1];
    }

    void clear(int p) { // 清空节点
        c[p][0] = c[p][1] = f[p] = val[p] = size[p] = cnt[p] = reverseTag[p] = 0;
    }

    int newNode(int k) {
        ++tot;
        val[tot] = k, cnt[tot] = 1;
        return tot;
    }

    void rotate(int p) {
        int fp = f[p], ffp = f[fp], chk = get(p);
        c[fp][chk] = c[p][chk ^ 1];
        if (c[p][chk ^ 1]) f[c[p][chk ^ 1]] = fp;
        c[p][chk ^ 1] = fp;
        f[fp] = p, f[p] = ffp;
        if (ffp) c[ffp][fp == c[ffp][1]] = p;
        updateSize(fp), updateSize(p);
    }

    void splay(int p, int goal = 0) {
        if (goal == 0) root = p;
        while (f[p] != goal) {
            int fp = f[p], ffp = f[fp];
            if (ffp != goal) {
                if (get(fp) == get(p))
                    rotate(fp);
                else
                    rotate(p);
            }
            rotate(p);
        }
    }

    void insert(int k) {
        if (root == 0) {
            root = newNode(k);
            updateSize(root);
            return;
        }
        int p = root, fp = 0;
        while (true) {
            if (val[p] == k) {
                cnt[p]++;
                updateSize(p), updateSize(fp);
                splay(p);
                break;
            }
            fp = p, p = c[p][val[p] < k];
            if (p == 0) {
                p = newNode(k);
                f[p] = fp, c[fp][val[fp] < k] = p;
                updateSize(p), updateSize(fp);
                splay(p);
                break;
            }
        }
    }

    int rank(int k) {
        int ans = 0, p = root;
        while (true) {
            if (k < val[p]) {
                p = c[p][0];
            } else {
                ans += size[c[p][0]];
                if (p == 0) return ans + 1;
                if (k == val[p]) {
                    splay(p);
                    return ans + 1;
                }
                ans += cnt[p];
                p = c[p][1];
            }
        }
    }

    int kth(int k) {
        int p = root;
        while (true) {
            pushdown(p);
            if (c[p][0] and k <= size[c[p][0]]) {
                p = c[p][0];
            } else {
                k -= cnt[p] + size[c[p][0]];
                if (k <= 0) {
                    splay(p);
                    return p;
                }
                p = c[p][1];
            }
        }
    }

    int pre() {
        int p = c[root][0];
        if (p == 0) return p;
        while (c[p][1]) p = c[p][1];
        splay(p);
        return p;
    }

    int suf() {
        int p = c[root][1];
        if (p == 0) return p;
        while (c[p][0]) p = c[p][0];
        splay(p);
        return p;
    }

    void del(int k) {
        rank(k);
        if (cnt[root] > 1) {
            cnt[root]--;
            updateSize(root);
            return;
        }
        if (c[root][0] == 0 and c[root][1] == 0) {
            clear(root);
            root = 0;
            return;
        }
        if (c[root][0] == 0) {
            int p = root;
            root = c[root][1];
            f[root] = 0;
            clear(p);
            return;
        }
        if (c[root][1] == 0) {
            int p = root;
            root = c[root][0];
            f[root] = 0;
            clear(p);
            return;
        }
        int p = root;
        int x = pre();
        f[c[p][1]] = x;
        c[x][1] = c[p][1];
        clear(p);
        updateSize(root);
    }

    int pre(int k) {
        insert(k);
        int ans = val[pre()];
        del(k);
        return ans;
    }

    int suf(int k) {
        insert(k);
        int ans = val[suf()];
        del(k);
        return ans;
    }

    void tagReverse(int p) {
        swap(c[p][0], c[p][1]);
        reverseTag[p] ^= 1;
    }

    void pushdown(int p) {
        if (reverseTag[p]) {
            tagReverse(c[p][0]);
            tagReverse(c[p][1]);
            reverseTag[p] = 0;
        }
    }

    void reverse(int l, int r) {
        int L = kth(l), R = kth(r + 2);
        splay(L), splay(R, L);
        int tmp = c[c[L][1]][0];
        tagReverse(tmp);
    }

    int build(int l, int r, int fp, const vector<int> &a) {
        if (l > r) return 0;
        int mid = (l + r) / 2;
        int p = newNode(a[mid]);
        f[p] = fp;
        c[p][0] = build(l, mid - 1, p, a);
        c[p][1] = build(mid + 1, r, p, a);
        updateSize(p);
        return p;
    }

    void init(vector<int> a) { // a 数组 1 base
        n = a.size() - 1;
        a.push_back(inf);
        root = build(0, n + 1, 0, a);
        return;
    }

    void display(int p) {
        pushdown(p);
        if (c[p][0]) display(c[p][0]);
        if (val[p] >= 1 and val[p] <= n) cout << val[p] << " ";
        if (c[p][1]) display(c[p][1]);
    }

    void display() {
        display(root);
        cout << "\n";
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Splay tree;
    vector<int> a(n + 1);
    iota(a.begin(), a.end(), 0);
    tree.init(a);
    for (int l, r; m; m--) {
        cin >> l >> r;
        tree.reverse(l, r);
    }
    tree.display();
    return 0;
}