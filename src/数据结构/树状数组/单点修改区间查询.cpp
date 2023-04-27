// lowbit 函数
#define lowbit(x) ( x & -x )
// O(N) 递推建树
void build(){
    for( int i = 1 , fa = i + lowbit(i) ; i <= n ; i ++ , fa = i + lowbit(i) )
        if( fa <= n ) bit[fa] += bit[i];
}
// 单点修改
void add( int x , int val ){
    for( int i = x ; i <= n ; i += lowbit(i) )
        bit[i] += val;
}
// 区间查询[1,x]的和
int getVal( int x ){
    int res = 0;
    for( int i = x ; i ; i -= lowbit(i) )
        res += bit[i];
    return res;
}