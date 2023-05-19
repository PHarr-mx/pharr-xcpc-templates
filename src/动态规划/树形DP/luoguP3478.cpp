// luogu P3478
#include<bits/stdc++.h>
using namespace std;
#define int long long

int read() {...}

int n;
vector<int> d, f, son;
vector<bool> vis;
vector<vector<int>> e;

void dfs(int x) {
    vis[x] = 1;
    for (auto y: e[x]) {
        if (vis[y]) continue;
        d[y] = d[x] + 1;
        dfs(y);
        son[x] += son[y];
    }
    return;
}

void dp(int x){
    vis[x] = 1;
    for( auto y : e[x] ){
        if( vis[y] ) continue;
        f[y] = f[x] + n - 2*son[y];
        dp(y);
    }
}


int32_t main() {
    n = read();
    d = vector<int>(n + 1), f = vector<int>(n + 1);
    son = vector<int>(n + 1, 1), son[0] = 0;
    vis = vector<bool>(n + 1);
    e = vector<vector<int>>(n+1);
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), e[u].push_back(v), e[v].push_back(u);
    dfs(1);
    vis = vector<bool>(n + 1);
    for( int i = 1 ; i <= n ; i ++ )
        f[1] += d[i];
    dp(1);
    int val = 0 , res = 0;
    for( int i = 1 ; i <= n ; i ++ )
        if( f[i] > val ) val = f[i] , res = i;
    cout << res;
    return 0;
}