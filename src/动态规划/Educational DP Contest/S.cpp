#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using vi = vector<i64>;

#define int i64

const int mod = 1e9 + 7;
int d;
vi a(1);
vector<vi> f;

int dp(int pos, int x, bool flag) {
    if (pos == 0) return x % d == 0;
    if (flag and f[pos][x] != -1) return f[pos][x];
    int ans = 0, n = flag ? 9 : a[pos];
    for (int i = 0; i <= n; i++)
        ans = (ans + dp(pos - 1, (x+ i) % d, flag or i < n)) % mod;
    if (flag) f[pos][x] = ans;
    return ans;
}

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string k;
    cin >> k >> d;
    reverse(k.begin(), k.end());
    for (auto i: k) a.push_back(i - '0');
    f = vector(a.size(), vi(d, -1));
    cout << (dp(a.size() - 1, 0, false) + mod - 1) % mod;
    return 0;
}