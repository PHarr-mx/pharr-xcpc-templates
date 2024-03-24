#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;
using vi = vector<i64>;

const i64 inf = 1e18;


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int N = n * 1e3;
    vi f(N + 1, inf);
    f[0] = 0;
    for (int w, v; n; n--) {
        cin >> w >> v;
        for (int i = N; i >= v; i--) f[i] = min(f[i], f[i - v] + w);
    }
    for (int i = N; i >= 0; i--)
        if (f[i] <= m) {
            cout << i << "\n";
            return 0;
        }
    return 0;
}