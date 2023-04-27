//NC-contest-38105-K
int read() {...}
priority_queue<int> q; vector<int> ve;
int32_t main() {
    int n = read();
    for( int i = 1 , x ; i <= n ; i ++ ){
        x = read() , q.push(x);
        if( x >= n ) // 如果度数大于 n 一定存在重边或自环
            cout << "NO\n" , exit(0);
    }
    while( 1 ){
        int k = q.top(); q.pop();
        if( k == 0 )
            cout << "YES\n" , exit(0);
        ve.clear();
        for( int x ; k ; k -- ){
            x = q.top() - 1 , q.pop();
            if( x < 0 )
                cout << "NO\n" , exit(0);
            ve.push_back(x);
        }
        for( auto it : ve ) q.push(it);
    }
    return 0;
}