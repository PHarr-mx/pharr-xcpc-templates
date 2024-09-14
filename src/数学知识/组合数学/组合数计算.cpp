// 暴力计算组合数
int C(int x, int y) { // x 中 选 y 个
    y = min(y, x - y);
    int res = 1;
    for (int i = x, j = 1; j <= y; i--, j++)
        res = res * i / j;
    return res;
}

// 加法递推O(n^2)
for( int i = 0 ; i <= n ; i ++ ){
    c[i][0] = 1;
    for( int j = 1 ; j <= i ; j ++)
        c[i][j] = c[i-1][j] + c[i-1][j-1];
}
// 乘法递推O(n)
c[0] = 1;
for( int i = 1 ; i * 2 <= n ; i ++ )
    c[i] = c[n-i] = ( n-i+1 ) * c[i-1] / i;

// 任意组合数
#define int long long
const int N = 5e5+5 , mod = 1e9+7;
int fact[N] , invFact[N];

int power(int x,int y){...} // 快速幂
int inv( int x ){...} // 求逆元，一般是费马小定理

int A( int x , int y ){ // x 中选 y 排序
    return fact[x] * invFact[x-y] % mod;
}

int C( int x , int y ){ // x 中选 y 个
    return fact[x] * invFact[x-y] % mod * invFact[y] % mod;
}

void init(){
    fact[0] = 1 , invFact[0] = inv(1);
    for( int i = 1 ; i < N ; i ++ )
        fact[i] = fact[i-1] * i % mod , invFact[i] = inv(fact[i]);
}