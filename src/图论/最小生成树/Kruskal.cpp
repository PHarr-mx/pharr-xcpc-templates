// Luogu P3366
const int N = 5005;
int n , m , fa[N] , cnt = 0 , sum;

int read() {...}

int getfa( int x ){...}

void merge( int x , int y ){...} // 并查集合并

int32_t main(){
    n = read() , m = read();
    for( int i = 1 ; i <= n ; i ++ ) fa[i] = i;
    vector<tuple<int,int,int>> e(m);
    for( auto & [ w , u , v ] : e )
        u = read() , v = read() , w = read();
    sort( e.begin() , e.end() );
    for( auto[ w , u , v ] : e ){
        if( getfa(u) == getfa(v) ) continue;
        merge( u , v ) , sum += w , cnt ++;
        if( cnt == n - 1 ) break;
    }
    if( cnt == n - 1 ) cout << sum << "\n";
    else cout << "orz\n";// 图不联通
    return 0;
}