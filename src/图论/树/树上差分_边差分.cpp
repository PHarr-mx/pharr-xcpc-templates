// Luogu P3128 边差分模板
#include<bits/stdc++.h>
using namespace std;

const int N = 5e4+5;
int n , m , fa[N][30] , logN , dep[N] ,p[N] , res;
vector<int> e[N];

int read(){...}

void dfs( int x ) {...} // 和 lca 的dfs完全相同

int lca( int x , int y ){...} // lca

void getRes( int x ){
    for( auto v : e[x] ){
        if( fa[x][0] == v ) continue;
        getRes(v) , p[x] += p[v];
    }
    res = max( res, p[x] );
}

int32_t main(){
    n = read() , m = read() , logN = log2(n)+1;
    for( int u , v , i = 1 ; i < n ; i ++ )
        u = read() , v = read() , e[u].push_back(v) , e[v].push_back(u);
    dep[1] = 1;
    dfs( 1 );
    for( int i = 1 , u , v , d ; i <= m ; i ++ ){
        u = read() , v = read() , d = lca( u , v );
        p[u] ++ , p[v] ++ , p[d] -- , p[ fa[d][0] ] --;
    }
    getRes( 1 );
    cout << res << "\n";
}