vector< pair<int,int> > factorize( int x ){
    vector<pair<int,int>> ans;
    for( int i = 2 , cnt ; i * i <= x ; i ++){
        if( x % i ) continue;
        cnt = 0;
        while( x % i == 0 ) cnt ++ , x /= i;
        ans.push_back( { i , cnt } );
    }
    if( x > 1 ) ans.push_back( { x , 1 } );
    return ans;
}