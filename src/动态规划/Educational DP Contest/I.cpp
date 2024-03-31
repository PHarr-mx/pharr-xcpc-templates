#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;
using ldb = long double;
#define int i64

using vi = vector<i64>;
using pii = pair<int, int>;
const i64 inf = 1e18;
const i64 mod = 1e9 + 7;

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n;
    vector<ldb> f(n + 1);
    f[0] = 1;
    for (ldb p, t = n; t > 0; t -= 1) {
        cin >> p;
        for (int i = f.size() - 1; i >= 0; i--) {
            f[i] *= (1.0 - p);
            if (i > 0) f[i] += f[i - 1] * p;
        }
    }
    ldb res = 0;
    for (int i = 0; i <= n; i++)
        res += (i * 2 > n) * f[i];
    cout << fixed << setprecision(10) << res << "\n";
    return 0;
}