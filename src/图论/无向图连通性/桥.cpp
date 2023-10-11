vector<pii> bridges;
vector<vi> e;
vi dfn, low, fa;
int cnt;

void tarjan(int x) {
    low[x] = dfn[x] = ++cnt;
    for (auto y: e[x]) {
        if (!dfn[y]) {
            fa[y] = x, tarjan(y);
            low[x] = min(low[x], low[y]);
            if (low[y] > dfn[x])
                bridges.emplace_back(x, y);
        } else if (fa[x] != y)
            low[x] = min(low[x], dfn[y]);
    }
    return;
}