int exgcd( int a , int b , int & x , int & y ){
    if( b == 0 ) { x = 1 , y = 0 ; return a;}
    int d = exgcd( b , a%b , x , y );
    int z = x ; x = y ; y = z - y * (a / b);
    return d;
}

template<typename T>
T exgcd(T a, T b, T &x, T &y){
    if (!b){
        x = 1, y = 0;
        return a;
    }
    T r = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return r;
}