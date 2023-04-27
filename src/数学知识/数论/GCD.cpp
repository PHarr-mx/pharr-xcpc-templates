int gcd( int x , int y ){ // 更相减损术
    while( x != y ){
        if( x > y ) x -= y;
        else y -=x;
    }
    return x;
}

int gcd( int x , int y ){ // 辗转相除法
    return b ? gcd( b , a % b ) : a ;
}

// 还有一种是直接调用库函数
__gcd( a , b );