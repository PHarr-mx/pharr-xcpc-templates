#include<bits/stdc++.h>
#define int long long
using namespace std;

int read() {
    int x = 0, f = 1, ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
    return x * f;
}

const int N = 5e5+5;
int a[N] , b[N];
int n , m , t , res;
int query( int l , int r ){
    if( r > n ) return 1e19;
    for( int i = l ; i <= r ; i ++ ) b[i] = a[i];
    sort( b + l , b + r + 1);
    int ans = 0;
    for( int i = l , j = r , t = 1 ; t <= m && i < j ; t ++ , i ++ , j -- )
        ans += ( b[i] - b[j] ) * ( b[i] - b[j] );
    return ans;
}

void solve(){
    n = read() , m = read() , t = read() , res = 0;
    for( int i = 1 ; i <= n ; i ++ ) a[i] = read();
    for( int l = 1 , r = 1 , p; l <= n ; l = r + 1 ){
        p = 1 , r = l;
        while( p ){
            if( query( l , r + p ) <= t ) r += p , p *= 2;
            else p /= 2;
        }
        res ++;
    }
    cout << res << "\n";
}

int32_t main() {
    for( int T = read(); T ; T -- ) solve();
    return 0;
}