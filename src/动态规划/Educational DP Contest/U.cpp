#include<bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;

#define int i64

using vi = vector<int>;

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector a(n, vi(n));
    for (auto &ai: a)
        for (auto &aij: ai)
            cin >> aij;

    const int N = 1 << n;
    vi f(N);
    for (int s = 1; s < N; s++) {
        for (int i = 0; i < n; i++) {
            if ((s & 1 << i) == 0) continue;
            for (int j = 0; j < i; j++) {
                if ((s & 1 << j) == 0) continue;
                f[s] += a[i][j];
            }
        }
        for (int i = s; i; i = (i - 1) & s)
            f[s] = max(f[s], f[i] + f[s ^ i]);
    }
    cout << f.back() << "\n";
    return 0;
}