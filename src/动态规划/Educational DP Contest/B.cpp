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
    int n, k;
    cin >> n >> k;
    vi h(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];
    vi f(n + 1, inf);
    f[1] = 0;
    for (int i = 2; i <= n; i++)
        for (int j = max(1ll, i - k); j < i; j++)
            f[i] = min(f[i], f[j] + abs(h[i] - h[j]));
    cout << f[n] << "\n";
    return 0;
}