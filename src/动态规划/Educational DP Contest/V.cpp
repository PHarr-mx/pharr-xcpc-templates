#include<bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;

#define int i64

using vi = vector<int>;

int n, mod;
vector<vi> e;
vi f1, f2;

void dp1(int x, int fa) {
    f1[x] = 1;
    for (auto y: e[x]) {
        if (y == fa) continue;
        dp1(y, x);
        f1[x] = (f1[x] * (f1[y] + 1)) % mod;
    }
    return;
}

void dp2(int x, int fa) {
    if (e[x].empty())return;
    vi pre(e[x].size()), suf(e[x].size());
    pre.front() = suf.back() = 1;
    for (int i = 1; i < e[x].size(); i++) {
        if (e[x][i - 1] == fa) pre[i] = pre[i - 1];
        else pre[i] = (pre[i - 1] * (f1[e[x][i - 1]] + 1)) % mod;
    }
    for (int i = e[x].size() - 2; i >= 0; i--) {
        if (e[x][i + 1] == fa) suf[i] = suf[i + 1];
        else suf[i] = (suf[i + 1] * (f1[e[x][i + 1]] + 1)) % mod;
    }
    for (int i = 0; i < e[x].size(); i++) {
        if (e[x][i] == fa) continue;
        f2[e[x][i]] = (f2[x] * pre[i] % mod * suf[i] % mod + 1) % mod;
        dp2(e[x][i], x);
    }
    return;
}


i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> mod;
    e.resize(n + 1), f1.resize(n + 1), f2.resize(n + 1);
    for (int x, y, i = 1; i < n; i++)
        cin >> x >> y, e[x].push_back(y), e[y].push_back(x);
    dp1(1, -1);
    f2[1] = 1, dp2(1, -1);
    for (int i = 1; i <= n; i++)
        cout << f1[i] * f2[i] % mod << "\n";
    return 0;
}