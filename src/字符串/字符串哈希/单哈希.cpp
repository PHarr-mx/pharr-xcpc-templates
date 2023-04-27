typedef unsigned long long ull;
const int N = 1e6+5 , K = 1e9+7;// 长度 K进制
vector<ull> hashP(N);

void init(){// 初始化
    hashP[0] = 1;
    for( int i = 1 ; i < N ; i ++ ) hashP[i] = hashP[i-1] * K;
}

void hashStr( const string & s , vector<ull> & a){ // 计算Hash数组
    a.resize(s.size()+1);
    for( int i = 1 ; i <= s.size() ; i ++ )
        a[i] = ull(a[i-1] * K + s[i-1]);
}

ull hashStr( const string & s ){
    ull ans = 0;
    for( auto i : s )
        ans = ull( ans * K + i );
    return ans;
}

ull getHash( int l , int r , const vector<ull> & a ){ //计算Hash值
    return a[r] - a[l-1] *  hashP[r-l+1];
}
