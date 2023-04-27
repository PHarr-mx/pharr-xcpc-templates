bool isPrime( int x ){
    for( int i = 1 ; i * i <= x ; i ++ )
        if( x % i == 0 ) return 0;
    return 1;
}