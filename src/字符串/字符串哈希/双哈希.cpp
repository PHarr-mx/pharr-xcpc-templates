#define int long long
#define mp make_pair
typedef pair<int, int> hashv;

const hashv mod = mp( 1e9+7 , 998244353 );
const hashv base = mp(13331,23333);

hashv operator + ( hashv a , hashv b ) {
    int c1 = a.first + b.first , c2 = a.second + b.second;
    if( c1 >= mod.first ) c1 -= mod.first;
    if( c2 >= mod.second ) c2 -= mod.second;
    return mp( c1 , c2 );
}

hashv operator - ( hashv a , hashv b ) {
    int c1 = a.first-b.first , c2 =a.second-b.second;
    if( c1 < 0 ) c1 += mod.first;
    if( c2 < 0 ) c2 += mod.second;
    return mp( c1 , c2 );
}

hashv operator * ( hashv a , hashv b ) {
    return mp( a.first*b.first%mod.first , a.second*b.second%mod.second );
}

const int N = 2e6+5;

vector< hashv > p , hs , ht;

void hashStr( const string &s , vector<hashv> &v ){
    v.resize(s.size()+1);
    for( int i = 1 ; i <= s.size() ; i ++ )
        v[i] = v[i-1] * base + mp( s[i-1] , s[i-1] );
    return;
}
hashv getHash( int l , int r , const vector<hashv> &v){
    if( l > r ) return mp( 0 , 0 );
    return v[r] - v[l-1] * p[r-l+1];
}
void init( int n ){
    p = vector<hashv>( n+1 ) , p[0] = mp(1,1);
    for( int i = 1 ; i <= n ; i ++ ) p[i] = p[i-1] * base;
}