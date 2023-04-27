\\ luogu P3379
const int N = 5e5+5;
int n , m , sta , dep[N] , fa[N];
vector<int> e[N];

int read() {...}
void dfs( int x ){
    for( auto v : e[x] ){
        if( v == fa[x] ) continue;
        dep[v] = dep[x] + 1 , fa[v] =x;
        dfs(v);
    }
}

int lca( int x , int y ){
    if( dep[x] < dep[y] ) swap( x , y );
    while( dep[x] > dep[y] ) x = fa[x];
    while( x != y ) x = fa[x] , y = fa[y];
    return x;
}

int32_t main() {
    n = read() - 1 , m = read() , sta = read();
    for( int u , v ; n ; n -- )
        u = read(),v = read() , e[u].push_back(v) , e[v].push_back(u);
    dep[sta] = 0 , fa[sta] = sta;
    dfs( sta );
    for( int x , y ; m ; m -- ){
        x = read() , y = read();
        cout << lca(x,y) << endl;
    }
    return 0;
}