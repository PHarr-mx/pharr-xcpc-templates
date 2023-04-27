// 求DFS序
vector<int> dfsSort;
vector<int> e[N];
bitset<N> vis;

void dfs( int x ){
    dfsSort.push_back(x) , vis[x] = 1;
    for( auto it : e[x] ){
        if( vis[it] ) continue;
        dfs( it );
    }
}
// 求欧拉序
vector<int> eulerSort;
vector<int> e[N];
bitset<N> vis;

void dfs( int x ){
    eulerSort.push_back(x) , vis[x] = 1;
    for( auto it : e[x] ){
        if( vis[it] ) continue;
        dfs( it );
    }
    eulerSort.push_back(x);
}