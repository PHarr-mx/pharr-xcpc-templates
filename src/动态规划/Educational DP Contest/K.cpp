#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;
using ldb = long double;

#define int long long

using vi = vector<int>;
using pii = pair<int, int>;

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (auto &i: a) cin >> i;
    vector<bool> f(k + 1);
    for (int i = 1; i <= k; i++)
        for (auto x: a) {
            if (i - x < 0) continue;
            if (f[i - x] == 0) {
                f[i] = 1;
                break;
            }
        }
    if (f.back()) cout << "First\n";
    else cout << "Second\n";
    return 0;
}