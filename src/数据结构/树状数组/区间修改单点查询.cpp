// op == 1 [l,r] 加上 val
// op == 2 查询位置 l 的值
int32_t main() {
    n = read() , m = read();
    for( int i = 1 , x = 0 , lst = 0; i <= n ; i ++ ) x = read() , bit[i] = x - lst , lst = x ;
    build();
    for( int op , l , r , val; m ; m -- ){
        op = read();
        if( op == 1 ) l = read() , r = read() , val = read() , add( l , val ) , add( r + 1 , - val );
        else l = read() , printf("%d\n" , getVal(l) );
    }
    return 0;
}