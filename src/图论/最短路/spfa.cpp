int dis[N] , cnt[N];
vector< pair<int,int> > e[N];
bitset<N> vis;

bool spfa(){
    for( int i = 1 ; i <= n ; i ++ ) dis[i] = inf;
    queue< int > q;
    dis[sta] = 0 , vis[sta] = 1 , q.push(sta);
    for( int u ; q.size() ; ){
        u = q.front() , q.pop() , vis[u] = 0;
        for( auto [ v , w ] : e[u] ){
            if( dis[v] <= dis[u] + w ) continue;
            dis[v] = dis[u] + w ;
            cnt[v] = cnt[u] + 1; // 记录最短路经过了几条边
            if( cnt[v] >= n ) // 最短路最长是 n-1
                return false; // 此时说明出现了 负环
            if( !vis[v] ) vis[v] = 1 , q.push(v);
        }
    }
    return true;
}
