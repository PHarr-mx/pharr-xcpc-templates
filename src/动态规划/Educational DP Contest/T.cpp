#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using vi = vector<i64>;

#define int i64

const int mod = 1e9 + 7;


i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    s = "  " + s;
    vi sum(n + 1, 1), f(n + 1);
    sum[0] = 0;
    for (int i = 2; i <= n; i++) {
        fill(f.begin(), f.end(), 0);
        for (int j = 1; j <= i; j++) {
            if (s[i] == '<') f[j] = sum[j - 1];
            else f[j] = (sum[i - 1] - sum[j-1] + mod) % mod;
        }
        for (int j = 1; j <= n; j++)
            sum[j] = (sum[j - 1] + f[j]) % mod;
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = (res + f[i]) % mod;
    cout << res << "\n";
    return 0;
}