#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;

#define int i64

using vi = vector<i64>;
using pii = pair<int, int>;
const i64 inf = 1e18;


i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vi> e(n + 1);
    vi inDeg(n + 1);
    for (int i = 1, x, y; i <= m; i++)
        cin >> x >> y, inDeg[y]++, e[x].push_back(y);
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (inDeg[i] == 0) q.push(i);
    vi dis(n + 1);
    for (int x; not q.empty();) {
        x = q.front(), q.pop();
        for (auto y: e[x]) {
            dis[y] = max(dis[y], dis[x] + 1);
            if (--inDeg[y] == 0) q.push(y);
        }
    }
    cout << ranges::max(dis) << "\n";
    return 0;
}