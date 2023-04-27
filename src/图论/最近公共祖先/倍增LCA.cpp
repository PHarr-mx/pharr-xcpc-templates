const int N = 5e5+5;
int n , m , sta , logN , dep[N] , fa[N][20];
vector<int> e[N];
int read() {...}

void dfs( int x ){
    for( auto v : e[x] ){
        if( dep[v] ) continue;
        dep[v] = dep[x] + 1 , fa[v][0] = x;
        for( int i = 1 ; i <= logN ; i ++ )
            fa[v][i] = fa[ fa[v][i-1] ][i-1];
        dfs(v);
    }
}
int lca( int x , int y ){
    if( dep[x] > dep[y] ) swap( x , y );
    for( int i = logN ; i >= 0 ; i -- )
        if( dep[ fa[y][i] ] >= dep[x] ) y = fa[y][i];
    if( x == y ) return x;
    for( int i = logN ; i >= 0 ; i -- ){
        if( fa[x][i] != fa[y][i] ) x = fa[x][i] , y = fa[y][i];
    }
    return fa[x][0];
}

int32_t main() {
    n=read()-1 , m=read() , sta=read() , logN =(int)log2(n) + 1;
    int k = n;
    for( int u , v ; n ; n -- )
        u=read() , v=read() , e[u].push_back(v) , e[v].push_back(u);
    dep[sta] = 1;
    dfs( sta );
    for( int x , y ; m ; m -- ){
        x = read() , y = read();
        cout << lca(x,y) << endl;
    }
    return 0;
}