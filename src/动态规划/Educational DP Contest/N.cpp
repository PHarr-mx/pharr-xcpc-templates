#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;
using ldb = long double;

#define int i64

using vi = vector<int>;
using pii = pair<int, int>;

const int inf = 1e18;
const int mod = 1e9 + 7;
const vi dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] += a[i - 1];
    vector f(n + 1, vi(n + 1, inf));
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    for (int len = 2; len <= n; len++)
        for (int l = 1, r = len; r <= n; l++, r++)
            for (int mid = l; mid + 1 <= r; mid++)
                f[l][r] = min(f[l][r], f[l][mid] + f[mid + 1][r] + a[r] - a[l - 1]);
    cout << f[1][n] << "\n";
    return 0;
}