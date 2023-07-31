// LOJ10119
const int N = 1e6+5 , logN = 20;
int a[N] , log_2[N] , f[N][ logN + 5 ];
int32_t main() {
    int n = read() , m = read();
    for( int i = 1 ; i <= n ; i ++ )
        a[i] = read();
    log_2[0] = -1; // 这样初始化可以使得 log_2[1] = 0

    for( int i = 1 ; i <= n ; i ++ ) // O(n) 预处理边界条件 和 log2(i)
        f[i][0] = a[i] , log_2[i] = log_2[i>>1] + 1;

    for( int j = 1 ; j <= logN ; j ++ )
        for( int i = 1; i + (1 << j) - 1 <= n ; i ++ )
            f[i][j] = max( f[i][j-1] , f[ i + ( 1 << j - 1 ) ][j-1] );

    for( int l , r , s ; m ; m -- ){
        l = read() , r = read() , s = log_2[ r - l + 1 ];
        printf("%d\n" , max( f[l][s] , f[ r - ( 1 << s ) + 1 ][s] ));
    }
    return 0;
}