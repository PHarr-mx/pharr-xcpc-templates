// NC51178
int32_t main() {
    int n;
    cin >> n;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];
    vector<vector<int>> e(n + 1);
    int root = n * (n + 1) / 2;
    for (int i = 1, x, y; i < n; i++)
        cin >> y >> x, e[x].push_back(y), root -= y;
    vector<array<int, 2>> f(n+1);
    auto dfs = [e, h, &f](auto &&self, int x) -> void {
        f[x][1] = h[x];
        for (auto y: e[x]) {
            self(self, y);
            f[x][0] += max(f[y][0], f[y][1]);
            f[x][1] += f[y][0];
        }
        return;
    };
    dfs(dfs, root);
    cout << max(f[root][1], f[root][0]);
    return 0;
}