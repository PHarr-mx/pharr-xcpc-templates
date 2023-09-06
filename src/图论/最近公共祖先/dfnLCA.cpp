// luogu P3379
#include <bits/stdc++.h>
using namespace std;

int dn;
vector<int> dfn;
vector <vector<int>> e, f;

void dfs(int x, int fa) {
    f[0][dfn[x] = ++dn] = fa;
    for (auto y: e[x])
        if (y != fa) dfs(y, x);
}
int get(int x, int y) {
    if (dfn[x] < dfn[y]) return x;
    return y;
}
int lca(int u, int v) {
    if (u == v) return u;
    u = dfn[u], v = dfn[v];
    if (u > v) swap(u, v);
    int d = log2(v - u++);
    return get(f[d][u], f[d][v - (1 << d) + 1]);
}
int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, root, logN;
    cin >> n >> m >> root;
    e.resize(n + 1), dfn.resize(n + 1);
    logN = log2(n);
    f = vector(logN + 1, vector<int>(n + 1));
    for (int i = 1, x, y; i < n; i++)
        cin >> x >> y, e[x].push_back(y), e[y].push_back(x);
    dfs(root, 0);

    for (int i = 1; i <= logN; i++)
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
            f[i][j] = get(f[i - 1][j], f[i - 1][j + (1 << i - 1)]);

    for (int x, y; m; m--) cin >> x >> y, cout << lca(x, y) << "\n";
    return 0;
}