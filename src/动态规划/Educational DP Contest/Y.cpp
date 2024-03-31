#include<bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;

#define int i64

using vi = vector<int>;
using pii = pair<int, int>;

const int mod = 1e9 + 7;
const int N = 2e5;

int power(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = ans * x % mod;
        x = x * x % mod, y /= 2;
    }
    return ans;
}

int inv(int x) {
    return power(x, mod - 2);
}

vi fact, invFact;

int C(int x, int y) {
    return fact[x] * invFact[x - y] % mod * invFact[y] % mod;
}

void init() {
    fact.resize(N + 1), invFact.resize(N + 1);
    fact[0] = 1, invFact[0] = inv(1);
    for (int i = 1; i <= N; i++)
        fact[i] = fact[i - 1] * i % mod, invFact[i] = inv(fact[i]);
    return;
}

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    init();
    int h, w, n;
    cin >> h >> w >> n;
    vector<pii> a(n);
    for (auto &[x, y]: a) cin >> x >> y;
    sort(a.begin(), a.end(), [&](const auto &x, const auto &y) {
        return x.first + x.second < y.first + y.second;
    });
    a.emplace_back(h, w);
    vi f(n + 1);
    for (int i = 0; i <= n; i++)
        f[i] = C(a[i].first + a[i].second - 2, a[i].first - 1);
    for (int i = 0; i <= n; i++) {
        auto &[xi, yi] = a[i];
        for (int j = 0; j <= n; j++) {
            auto &[xj, yj] = a[j];
            if (i == j or xi < xj or yi < yj) continue;
            f[i] = (f[i] - f[j] * C(xi + yi - xj - yj, xi - xj) % mod + mod) % mod;
        }
    }
    cout << f[n] << "\n";
    return 0;
}