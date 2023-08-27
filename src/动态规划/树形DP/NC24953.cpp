// NC 24953
int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> e(n + 1);
    for (int i = 1, x, y; i < n; i++)
        cin >> x >> y, e[x].push_back(y), e[y].push_back(x);
    vector<array<int, 3>> f(n + 1);
    // f[x][0] x 被自己覆盖,f[x][1] x 被儿子覆盖,f[x][2] x 被父亲覆盖
    auto dfs = [&f, e](auto &&self, int x, int fa) -> void {
        f[x][0] = 1;
        f[x][1] = inf;
        f[x][2] = 0;
        int inc = inf;
        for (auto y: e[x]) {
            if (fa == y) continue;
            if (f[x][1] == inf) f[x][1] = 0;
            self(self, y, x);
            f[x][0] += min({f[y][0], f[y][1], f[y][2]});
            f[x][2] += min(f[y][0], f[y][1]);
            f[x][1] += min(f[y][0], f[y][1]), inc = min(inc, f[y][0] - f[y][1]);
        }
        f[x][1] += max(0, inc);
        return;
    };

    dfs(dfs, 1, -1);
    cout << min(f[1][0], f[1][1]);
    return 0;
}