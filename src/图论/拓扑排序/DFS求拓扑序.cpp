vector<int> e[N]; // 邻接表
vector<int> topo; // 存储拓扑序
set<int> notInDeg;// 储存没有入读的点
int vis[N];

bool dfs( int u ){
    vis[u] = 1;
    for( auto v : e[u] ){
        if( vis[v] )  return 0;
        if( !dfs(v) ) return 0;
    }
    topo.push_back(u);
    return 1;
}

bool topSort(){
    if( notInDeg.empty() ) return 0 ;
    for( int u : notInDeg ){
        if( !dfs(u) ) return 0;
    }
    reverse( topo.begin() , topo.end() );
    return 1;
}