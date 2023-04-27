dep[sta] = 1;

void dfs( int u ){
    for( auto v : e[u] ){
        if( dep[v] ) continue;
        dep[v] = dep[u] + 1;
        dfs( v );
    }
}

dfs(sta);