vector<vector<int>> e;

int cnt = 0;
vector<int> dfn, low;
vector<int> cut; // 储存所有的割点

void tarjan( int p , bool root = true ){
    int tot = 0;
    low[p] = dfn[p] = ++ cnt;
    for( auto q : e[p] ){
        if( !dfn[q] ){
            tarjan( q , false );
            low[p] = min( low[p] , low[q] );
            tot += ( low[q] >= dfn[p]); // 统计满足条件的子节点数
        }else low[p] = min( low[p] , dfn[q] );
    }
    if( tot > root ) cut.push_back(p);
    return ;
}