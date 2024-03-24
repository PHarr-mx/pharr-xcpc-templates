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
    vi h(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];
    vi f(n + 1);
    f[1] = 0, f[2] = abs(h[2] - h[1]);
    for (int i = 3; i <= n; i++)
        f[i] = min(f[i - 1] + abs(h[i] - h[i - 1]), f[i - 2] + abs(h[i] - h[i - 2]));
    cout << f[n] << "\n";
    return 0;
}