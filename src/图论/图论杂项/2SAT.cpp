// luogu P4782
int32_t main() {
    int n, m, N;
    cin >> n >> m, N = n * 2 + 2;
    e.resize(N);
    dfn = inStk = low = scc = vector<int>(N);
    capacity.push_back(0);
    for (int i, a, j, b; m; m--) {
        cin >> i >> a >> j >> b;
        e[2 * i + (a ^ 1)].push_back(2 * j + b);
        e[2 * j + (b ^ 1)].push_back(2 * i + a);
    }
    for (int i = 2; i <= n * 2 + 1; i++)
        if (!dfn[i])
            tarjan(i);
    vector<int> res(n + 1);
    for (int i = 1; i <= n; i++) {
        if (scc[i * 2] == scc[i * 2 + 1])
            cout << "IMPOSSIBLE\n", exit(0);
        else if (scc[i * 2] > scc[i * 2 + 1])
            res[i] = 1;
    }
    cout << "POSSIBLE\n";
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    cout << "\n";
    return 0;
}