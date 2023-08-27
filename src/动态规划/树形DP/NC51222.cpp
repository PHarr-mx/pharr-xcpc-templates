// NC 51222
int32_t main() {
    int n;
    while (cin >> n) {
        vector<vector<int>> e(n);
        vector<array<int, 2>> f(n);
        int root = n * (n - 1) / 2;
        for (int x, y, t, i = 1; i <= n; i++)
            for( x = read() , t = read() ; t ; t -- )
                y = read(), e[x].push_back(y), root -= y;
        auto dfs = [e, &f](auto &&self, int x) -> void {
            f[x][1] = 1;
            for (auto y: e[x]) {
                self(self, y);
                f[x][1] += min(f[y][0], f[y][1]);
                f[x][0] += f[y][1];
            }
        };
        dfs(dfs, root);
        cout << min(f[root][1], f[root][0]) << "\n";
    }
    return 0;
}