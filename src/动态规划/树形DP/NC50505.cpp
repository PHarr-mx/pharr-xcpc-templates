int32_t main() {
    int n;
    cin >> n;
    vector<int> val(n + 1);
    vector<vector<int>> e(n + 1);
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1, x, y; i < n; i++)
        cin >> x >> y, e[x].push_back(y), e[y].push_back(x);
    vector<int> f(n + 1 , - inf ), dis(n + 1);
    // f[x] 表示 x 的子树的直径 , dis[x] 表示 x 向下最远可以走多远
    auto dfs = [e, val, &f, &dis](auto &&self, int x, int fa) -> void {
        multiset<int> t;
        for (auto y: e[x]) {
            if (y == fa) continue;
            self(self, y, x);
            f[x] = max(f[x], f[y]);
            dis[x] = max(dis[x], dis[y] + val[y]);
            t.insert(dis[y] + val[y]);
            if (t.size() == 3) t.erase(t.begin());
        }
        int w = val[x];
        for (auto i: t) w += i;
        f[x] = max(f[x], w);
        return;
    };
    dfs(dfs, 1, -1);
    return 0;
}