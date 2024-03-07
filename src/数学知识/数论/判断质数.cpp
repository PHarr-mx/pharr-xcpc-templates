bool isPrime( int x ){
    if( x < 3 or x % 2 == 0 ) return x == 2;
    for( int i = 2 ; i * i <= x ; i ++ )
        if( x % i == 0 ) return 0;
    return 1;
}