// Loj 2491
// 一颗树根节点是 1 , 点权就是深度的 k 次方
// m次询问,每次问(u,v)路径上点权之和
// k 每次都不同但是取值范围只有[1,50]
#define int long long
const int N = 3e5+5 , mod = 998244353;
int n , sum[N][55] , fa[N][20] , dep[N] , logN;
vector<int> e[N];

int read(){...}

void dfs( int x ){
    for( auto v : e[x] ){
        if( v == fa[x][0] ) continue;
        dep[v] = dep[x] + 1 , fa[v][0] = x;
        for( int i = 1 , val = 1; i <= 50 ; i ++ )
            val = val * dep[v]% mod , sum[v][i] = (val + sum[x][i]) % mod;
        for( int i = 1 ; i <= logN ; i ++ )
            fa[v][i] = fa[ fa[v][i-1] ][i-1];
        dfs(v);
    }
}

int lca( int x , int y ){...}

int32_t main(){
    n = read() , logN = (int)log2(n)+1;
    for( int i = 2 , u , v ; i <= n ; i ++ )
        u = read() , v = read() , e[u].push_back(v) , e[v].push_back(u);
    dep[1] = 0;
    dfs( 1 );
    for( int m = read() , u , v , k , t ; m ; m -- ){
        u = read() , v = read() , k = read() , t = lca( u , v );
        cout << (sum[u][k]+sum[v][k]-sum[t][k]-sum[fa[t][0]][k]+2*mod)%mod << "\n";
    }
    return 0;
}