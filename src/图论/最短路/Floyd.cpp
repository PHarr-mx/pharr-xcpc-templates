int dis[N][N];
for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j < i ; j ++ )
        dis[i][j] = dis[j][i] = inf;

for( int u , v , w ; m ; m -- )
    u = read() , v = read() , w = read() , dis[u][v] = dis[v][u] = w;
for( int k = 1 ; k <= n ; k ++ )
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j < i ; j ++ )
            f[i][j] = f[j][i] = min( f[i][j] , f[i][k] + f[k][j] );