//LOJ 10134 树上前缀和 边
const int N = 1e4+5;

int n , m , sum[N] , logN , dep[N] , fa[N][15];
vector<pair<int,int>> e[N];

int read(){...}

void dfs( int x ){ // 这里和 lca 极其类似，就是在多维护了一个前缀和
    for( auto [v,w] : e[x] ){
        if( dep[v] ) continue;
        dep[v] = dep[x] + 1 , fa[v][0] = x , sum[v] = sum[x] + w;
        for( int i = 1 ; i <= logN ; i ++ )
            fa[v][i] = fa[ fa[v][i-1] ][ i-1 ];
        dfs(v);
    }
}

int lca( int x , int y ){...}//这里就是 lca 的板子

int main(){
    n = read() , m = read() ,logN = (int)log2(n)+1;
    for( int i = 2 , u , v , w ; i <= n ; i ++ )
        u = read() , v = read() , w = read() , e[u].push_back( {v,w} ) , e[v].push_back( {u,w} );
    dep[1] = 1 , dfs(1);
    for( int u , v ; m ; m -- ){
        u = read() , v = read();
        cout << sum[u] + sum[v] - 2 * sum[ lca(u,v) ] << "\n";
    }
    return 0;
}