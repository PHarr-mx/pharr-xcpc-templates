#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;


using vi = vector<i64>;
using pii = pair<i64, i64>;

const i64 mod = 1e9 + 7;

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector a(n, vi(n));
    for (auto &ai: a)
        for (auto &aij: ai) cin >> aij;
    int N = 1 << n;
    vector f(n+1, vi(N));
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int t = 0; t < N; t++) {
            if (i != __builtin_popcount(t)) continue;
            for (int j = 0; j < n; j++) {
                if ((1 << j) & t == 0 or a[i - 1][j] == 0) continue;
                f[i][t] = (f[i][t] + f[i - 1][t ^ (1 << j)]) % mod;
            }
        }
    }
    cout << f[n][N - 1] << "\n";
    return 0;
}