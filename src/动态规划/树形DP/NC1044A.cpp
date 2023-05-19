// NC1044A
#include <bits/stdc++.h>
using namespace std;
int read() { ... }

int n, root;
vector<bool> v;
vector<int> h;
vector <vector<int>> e, f;

void dp(int x) {
    f[x][1] = h[x];
    for (auto y: e[x]) {
        dp(y);
        f[x][1] += f[y][0];
        f[x][0] += max(f[y][0], f[y][1]);
    }
}
int32_t main() {
    n = read();
    v = vector<bool>(n + 1, 0), h = vector<int>(n + 1);
    e = vector < vector < int >> (n + 1);
    f = vector < vector < int >> (n + 1, vector<int>(2));
    for (int i = 1; i <= n; i++) h[i] = read();
    for (int i = 1, x, y; i < n; i++)
        x = read(), y = read(), e[y].push_back(x), v[x] = 1;
    for (int i = 1; i <= n; i++) {
        if (v[i]) continue;
        root = i;
        break;
    }
    dp(root);
    cout << max(f[root][0], f[root][1]);
    return 0;
}