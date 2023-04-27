int h[N] , l[N]; // h[i] 用来记录每一个点的高度 l[i] 记录每一个左侧第一个比 i 高的点的位置
stack<int> stk;

h[0] = INF; //为了便于处理把 0 处理为正无穷
stk.push( h[0] );
for( int i = 1 ; i <= n ; i ++ ){
    while( h[i] >= h[ stk.top() ] ) stk.pop();
    l[i] = stk.top() , stk.push(i);
}