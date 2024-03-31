#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;
using ldb = long double;

#define int long long

using vi = vector<int>;
using pii = pair<int, int>;
const int mod = 1e9 + 7;
const int inf = 1e18;

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vi a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector f(n + 1, vi(k + 1)), sum(n + 1, vi(k + 1));
    f[1][0] = sum[1][0] = 1;
    for (int i = 1; i <= k; i++)
        f[1][i] = i <= a[1], sum[1][i] = sum[1][i - 1] + f[1][i];
    for (int i = 2; i <= n; i++) {
        f[i][0] = sum[i][0] = 1;
        for (int j = 1; j <= k; j++) {
            if (j <= a[i]) f[i][j] = sum[i - 1][j];
            else f[i][j] = (sum[i - 1][j] - sum[i - 1][j - a[i] - 1] + mod) % mod;
            sum[i][j] = (sum[i][j - 1] + f[i][j]) % mod;
        }
    }
    cout << f[n][k] << "\n";
    return 0;
}