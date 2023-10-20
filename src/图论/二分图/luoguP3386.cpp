// luogu P3386
//给定一个二分图，其左侧点n个，右侧点的个数为m，边数为k，求其最大匹配的边数。
//左侧点编号[1,n]，右侧点编号[1,m]。
#include <bits/stdc++.h>

using namespace std;

int n, m, k; // 左右两个集合的元素数量
vector<vector<int>> e;
vector<int> p; // 当前右侧集合对于左侧的元素
vector<bool> vis;// 右侧元素是否已经被访问过

bool match(int x) {
    for (auto y: e[x]) {
        if (vis[y]) continue;
        vis[y] = 1;
        if (p[y] == 0 or match(p[y])) { // 暂未匹配或原来匹配的左侧元素可以找到新的匹配
            p[y] = x;
            return true;
        }
    }
    return false;
}

int Hungarian() {
    int cnt = 0;
    p = vector<int>(n + m + 1);
    for (int i = 1; i <= n; i++) { // 枚举左侧元素
        vis = vector<bool>(n + m + 1);
        if (match(i)) cnt++;
    }
    return cnt;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m >> k;
    e = vector<vector<int>>(n + m + 1);

    for (int x, y; k; k--) {
        cin >> x >> y;
        y += n; // 为了方便表示把右侧点映射为 [n+1,n+m]
        e[x].push_back(y), e[y].push_back(x);
    }
    cout << Hungarian() << "\n";
    return 0;
}