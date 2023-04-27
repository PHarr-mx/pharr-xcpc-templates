vector< int > prime;
bool notPrime[N];;//不是素数

void getPrimes( int n ){
    notPrime[1] = notPrime[0] = 1;
    for( int i = 2 ; i <= n ; i ++ ){
        if( !notPrime[i] ) prime.push_back(i);
        for( auto it : prime ){
            if( it * i > n ) break;
            notPrime[ it * i ] = 1;
            if( i % it == 0 ) break;
        }
    }
}