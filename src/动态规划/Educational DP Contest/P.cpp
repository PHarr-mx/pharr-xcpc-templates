#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;

#define int i64

using vi = vector<i64>;
using pii = pair<i64, i64>;

const i64 mod = 1e9 + 7;

vector<vi> e;
vector<array<int, 2>> f;

void dfs(int x, int fa) {
    f[x][0] = f[x][1] = 1;
    for (auto y: e[x]) {
        if (y == fa) continue;
        dfs(y, x);
        f[x][1] = f[x][1] * f[y][0] % mod;
        f[x][0] = f[x][0] * (f[y][0] + f[y][1]) % mod;
    }
    return;
}

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    e.resize(n + 1), f.resize(n + 1);
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, -1);
    cout << (f[1][0] + f[1][1]) % mod;
    return 0;
}