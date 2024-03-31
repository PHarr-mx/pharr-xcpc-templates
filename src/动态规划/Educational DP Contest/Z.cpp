#include<bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;
using ldb = long double;

#define int i64

using vi = vector<int>;
using pii = pair<int, int>;

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, C;
    cin >> n >> C;
    vi h(n + 1), f(n + 1), g(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];
    auto slop = [&](int x, int y) {
        return ldb(g[x] - g[y]) / ldb(h[x] - h[y]);
    };
    deque<int> q;
    q.push_back(1), g[1] = h[1] * h[1];
    for (int i = 2, j; i <= n; i++) {
        while (q.size() >= 2 and slop(q.front(), *(q.begin() + 1)) <= 2 * h[i]) q.pop_front();
        j = q.front();
        f[i] = h[i] * h[i] + C + g[j] - 2 * h[i] * h[j];
        g[i] = f[i] + h[i] * h[i];
        while (q.size() >= 2 and slop(*(q.rbegin() + 1), q.back()) >= slop(q.back(), i)) q.pop_back();
        q.push_back(i);
    }
    cout << f[n];
    return 0;
}