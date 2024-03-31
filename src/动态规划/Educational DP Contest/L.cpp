#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;
using ldb = long double;

#define int long long

using vi = vector<int>;
using pii = pair<int, int>;

const int inf = 1e18;

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vi a(n);
    for (auto &i: a) cin >> i;
    vector f(n, vi(n, -inf));
    auto calc = [&](auto &&self, int l, int r) -> i64 {
        if (l > r) return 0ll;
        if (f[l][r] != -inf) return f[l][r];
        f[l][r] = max(a[l] - self(self, l + 1, r), a[r] - self(self, l, r - 1));
        return f[l][r];
    };
    cout << calc(calc, 0, n - 1) << "\n";
    return 0;
}