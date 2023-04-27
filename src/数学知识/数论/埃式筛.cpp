vector< int > prime;
bitset<N>notPrime;//不是素数

void getPrimes( int n ){
    notPrime[1] = notPrime[0] = 1;
    for( int i = 2 ; i <= n ; i ++ ){
        if( notPrime[i] ) continue;
        prime.push_back(i);
        for( int j = i * 2 ; j <= n ; j += i )
            notPrime[j] = 1;
    }
}

// 如果不需要 prime 数组的话可以优化成下面的代码
bitset<N>notPrime;//不是素数

void getPrimes( int n ){
    notPrime[1] = notPrime[0] = 1;
    for( int i = 2 ; i * i <= n ; i ++ ){
        if( notPrime[i] ) continue;
        for( int j = i * 2 ; j <= n ; j += i )
            notPrime[j] = 1;
    }
}