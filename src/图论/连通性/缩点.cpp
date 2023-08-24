for( int x = 1 ; x <= n ; x ++ )
    for( auto y : e[x] )
        if( scc[x] != scc[y] ) g[scc[x]].push_back( scc[y] );