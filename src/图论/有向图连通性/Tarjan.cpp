int cnt = 0, sc = 0; // cnt 记录 dfs 序 , sc 记录 强连通分量编号
stack<int> stk;
vector<int> dfn, low, inStk, scc, capacity;
// low[i] 点i所在子树的节点经过最多一条非树边能到达的结点中最小的dfs序
void tarjan(int x) {
    low[x] = dfn[x] = ++cnt;
    inStk[x] = 1, stk.push(x);
    for (auto y: e[x]) {
        if (!dfn[y])
            tarjan(y), low[x] = min(low[x], low[y]);
        else if (inStk[y])
            low[x] = min(low[x], dfn[y]);
    }
    if (low[x] == dfn[x]) {
        sc++, capacity.push_back(0);
        for (int y; true;) {
            y = stk.top(), stk.pop();
            inStk[y] = 0, scc[y] = sc, capacity[sc]++;
            if (x == y) break;
        }
    }
}

// 因为有向图搜索会形成森林
for (int i = 1; i <= n; i++)
    if (!dfn[i]) tarjan(i);