void dij(){
    for( int i = 1 ; i <= n ; i ++ ) dis[i] = inf;
    dis[sta] = 0;
    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > q;
    q.push( { 0 , sta } );
    while( q.size() ){
        int u = q.top().second ; q.pop();
        if( vis[u] ) continue;
        vis[u] = 1;
        for( auto [v,w] : e[u] )
            if( dis[v] > dis[u] + w ){
                dis[v] = dis[u] + w;
                q.push( {dis[v] , v } );
            }
    }
}