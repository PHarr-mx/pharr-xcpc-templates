bool bellmanFord(){ // 返回是否有最短路
    for( int i = 1 ; i <= n ; i ++ ) dis[i] = inf;
    dis[sta] = 0;
    bool flag;
    for( int i = 1 ; i <= n ; i ++ ){
        flag = 0;
        for( int u = 1 ; u <= n ; u ++ ){
            if( dis[u] == inf ) continue; // 如果当前点和起点没有联通，就无法进行松弛操作
            for( auto [v,w] : e[u] ){
                if( dis[v] <= dis[u] + w ) continue;
                dis[v] = dis[u] + w , flag = 1;// 记录时候进行松弛操作
            }
        }
        if( !flag ) break;
    }
    return flag;
}