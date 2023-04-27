//AcWing 138. 兔子与兔子
#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const int N = 1e6+5;
int n ;
ull Hash[N] , p[N] , P = 131;
string s;

int read() {...}

ull getHash( int l , int r ){
    return Hash[r] - Hash[l-1] * p[ r - l + 1 ];
}

int32_t main() {
    cin >> s;
    n = s.size() , p[0] = 1;
    for( int i = 1 ; i <= n ; i ++ )
        Hash[i] = Hash[i-1] * P + (s[i-1]-'a'+1) , p[i] = p[i-1] * P;
    for( int m = read() , l1 , r1 , l2 , r2 ; m ; m -- ){
        l1 = read() , r1 = read() , l2 = read() , r2 = read();
        if( getHash(l1,r1) == getHash(l2,r2) ) printf("Yes\n");
        else printf("No\n");
    }
}