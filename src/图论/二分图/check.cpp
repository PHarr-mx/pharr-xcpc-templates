vector<vector<int>> e;
vector<int> v; // 会把所有的点染成 1 2 两种颜色
bool flag;

void dfs( int x , int color ){
    v[x] = color;
    for( auto y : e[x] ){
        if( v[y] == 0 ) dfs( y , 3 - color );
        else if( v[y] == color ){
            flag = false;
            return ;
        }
    }
}

bool check(){
    flag = true;
    for( int i = 1 ; flag and i <= n ; i ++ ){
        if( v[i] ) continue;
        dfs( i , 1 );
    }
    return flag;
}