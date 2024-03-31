#include<bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;

#define int i64

using vi = vector<int>;

const int N = 2e4;

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for (auto &[w, s, v]: a) cin >> w >> s >> v;
    sort(a.begin(), a.end(), [&](const auto x, const auto &y) {
        return x[0] + x[1] < y[0] + y[1];
    });
    vi f(N + 1);
    for (const auto &[w, s, v]: a)
        for (int i = s; i >= 0; i--)
            f[i + w] = max(f[i + w], f[i] + v);
    cout << ranges::max(f);
    return 0;
}