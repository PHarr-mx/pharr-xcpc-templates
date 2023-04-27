vector<int> e[N]; // 邻接表
vector<int> topo; // 存储拓扑序
int inDeg[N]; // 记录点的当前入度

bool topSort(){
    queue<int> q;
    for( int i = 1 ; i <= n ; i ++ )
        if( inDeg[i] == 0 ) q.push(i);
    while( q.size() ){
        int u = q.front() ; q.pop();
        topo.push_back(u);
        for( auto v : e[u] ){
            if( --inDeg[v] == 0 ) q.push(v);
        }
    }
    return topo.size() == n;
}
