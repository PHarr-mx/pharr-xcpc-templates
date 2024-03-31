#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;

#define int i64

using vi = vector<i64>;
using pii = pair<int, int>;
const i64 inf = 1e18;
const i64 mod = 1e9 + 7;

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto &i: g) cin >> i;
    vector f(n, vi(m));
    f[0][0] = (g[0][0] == '.');
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (i == 0 and j == 0) continue;
            if (g[i][j] == '#') continue;
            if (i > 0) f[i][j] = (f[i][j] + f[i - 1][j]) % mod;
            if (j > 0) f[i][j] = (f[i][j] + f[i][j - 1]) % mod;
        }
    cout << f[n - 1][m - 1] << "\n";
    return 0;
}