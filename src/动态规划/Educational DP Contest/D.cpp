#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;
using vi = vector<i64>;


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vi f(m + 1);
    for (int w, v; n; n--) {
        cin >> w >> v;
        for (int i = m; i >= w; i--) f[i] = max(f[i], f[i - w] + v);
    }
    cout << f.back() << "\n";
    return 0;
}