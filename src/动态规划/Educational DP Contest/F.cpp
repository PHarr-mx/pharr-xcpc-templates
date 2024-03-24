#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;

#define int i64

using vi = vector<i64>;
using pii = pair<int, int>;
const i64 inf = 1e18;


i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    vector f(n + 1, vi(m + 1)), is(n + 1, vi(m + 1));
    vector lst(n + 1, vector<pii>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (f[i - 1][j] > f[i][j - 1]) f[i][j] = f[i - 1][j], lst[i][j] = pair(i - 1, j);
            else f[i][j] = f[i][j - 1], lst[i][j] = pair(i, j - 1);
            if (a[i - 1] == b[j - 1] and f[i - 1][j - 1] + 1 > f[i][j])
                is[i][j] = 1, f[i][j] = f[i - 1][j - 1] + 1, lst[i][j] = pair(i - 1, j - 1);
        }
    string res = "";
    for (int i = n, j = m; i and j;) {
        if (is[i][j]) res += a[i - 1];
        tie(i, j) = lst[i][j];
    }
    reverse(res.begin(), res.end());
    cout << res << "\n";
    return 0;
}