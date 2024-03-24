#include<bits/stdc++.h>

using namespace std;

#define int long long
using vi = vector<int>;
using i32 = int32_t;
using pii = pair<int, int>;
using vii = vector<pii>;

const int inf = 1e9, INF = 1e18;
const int mod = 1e9 + 7;
const vi dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<array<int, 3>> v(n), f(n);
    for (auto &it: v)
        for (auto &i: it) cin >> i;
    f[0] = v[0];
    for (int i = 1; i < n; i++)
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++)
                if (x != y) f[i][x] = max(f[i][x], f[i - 1][y]);
            f[i][x] += v[i][x];
        }
    cout << ranges::max(f.back()) << "\n";
    return 0;
}