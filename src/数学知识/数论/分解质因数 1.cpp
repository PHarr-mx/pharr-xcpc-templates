vector< int > factorize( int x ){
    vector<int> ans;
    for( int i = 2 ; i * i <= x ; i ++){
        while( x % i == 0 )
            ans.push_back(i) , x /= i;
    }
    if( x > 1 ) ans.push_back(x);
    return ans;
}