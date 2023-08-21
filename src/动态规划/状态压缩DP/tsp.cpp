// https://www.acwing.com/problem/content/93/
// 这道题给了额外的限定，要求起点必须从 0 开始
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20, M = 1 << N, inf = 1e17;
int e[N][N], f[M][N], n;

int calc(int st, int i) {
    if (f[st][i] != inf) return f[st][i];
    f[st][i] --; // 标记当前状态被访问过了，以免当前状态无解被反复访问
    int p = st - (1 << i);
    for (int j = 0; j < n; j++) {
        if ((p & (1 << j)) == 0) continue;
        f[st][i] = min(f[st][i], calc(p, j) + e[j][i]);
    }
    return f[st][i];
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> e[i][j]; // 边权
    fill(f[0], f[0] + M * N, inf) , f[1][0] = 0;
    cout << calc( ( 1 << n ) - 1 , n - 1 );
    return 0;
}