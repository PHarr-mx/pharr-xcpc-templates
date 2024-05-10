// luogu P3369
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct Splay {
    int root, tot;

    array<int, N> f, val, cnt, size;
    array <array<int, 2>, N> c;

    void updateSize(int p) {
        size[p] = size[c[p][0]] + size[c[p][1]] + cnt[p];
        return;
    }

    bool get(int p) { // 判断 p 是不是父亲的右儿子
        return p == c[f[p]][1];
    }

    void clear(int p) { // 清空节点
        c[p][0] = c[p][1] = f[p] = val[p] = size[p] = cnt[p] = 0;
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

//    如果只换到根节点可以简写
//    int splay(int p) {
//        for (int fp = f[p]; fp = f[p], fp; rotate(p))
//            if (f[fp]) rotate(get(p) == get(fp) ? fp : p);
//        return root = p;
//    }

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
            if (c[p][0] and k <= size[c[p][0]]) {
                p = c[p][0];
            } else {
                k -= cnt[p] + size[c[p][0]];
                if (k <= 0) {
                    splay(p);
                    return val[p];
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
};

int main() {
    int n;
    cin >> n;
    Splay tree;
    for (int opt, x; n; n--) {
        cin >> opt >> x;
        if (opt == 1) {
            tree.insert(x);
        } else if (opt == 2) {
            tree.del(x);
        } else if (opt == 3) {
            cout << tree.rank(x) << "\n";
        } else if (opt == 4) {
            cout << tree.kth(x) << "\n";
        } else if (opt == 5) {
            cout << tree.pre(x) << "\n";
        } else {
            cout << tree.suf(x) << "\n";
        }
    }
    return 0;
}