#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5+5;
int n , m , a[N];

struct Node{
    int l , r , value , add;
    Node * left , * right;
    Node( int l , int r , int value , int add , Node * left , Node * right ) :
            l(l) , r(r) , value(value) , add(add) , left(left) , right(right) {};
} * root;

int read() {...}
// 建树
Node * build( int l , int r ){
    if( l == r ) return new Node( l , r , a[l] , 0 , nullptr , nullptr );
    int mid = ( l + r ) >> 1;
    Node * left = build( l , mid ) , * right = build( mid + 1 , r );
    return new Node( l , r , left->value+right->value,0,left , right);
}
// 标记
void mark( int v , Node * cur ){
    cur -> add += v;
    cur -> value += v * ( cur->r - cur->l + 1 );
}
// 标记下传
void pushdown( Node * cur ){
    if( cur -> add == 0 ) return;
    mark( cur -> add , cur -> left ) , mark( cur -> add , cur -> right );
    cur -> add = 0;
}
// 修改
void modify( int l , int r , int v , Node * cur ){
    if( l > cur -> r || r < cur -> l ) return;
    if( l <= cur -> l && r >= cur -> r ){
        mark( v , cur );
        return;
    }
    pushdown( cur );
    int mid = ( cur -> l + cur -> r ) >> 1;
    if( l <= mid ) modify( l , r , v , cur -> left );
    if( r > mid ) modify( l , r , v , cur -> right );
    cur -> value = cur ->left->value + cur ->right->value;
    return ;
}
// 查询
int query( int l , int r , Node * cur ){
    if( l <= cur->l && r >= cur ->r ) return cur->value;
    pushdown( cur );
    int mid = ( cur->l + cur->r ) >> 1 , res = 0;
    if( l <= mid ) res += query( l , r , cur->left );
    if( r > mid ) res += query( l , r , cur->right );
    return res;

}

int32_t main(){
    n = read() , m = read();
    for( int i = 1 ; i <= n ; i ++ ) a[i] = read();
    root = build( 1 , n );
    for( int i = 1 , opt , l , r ; i <= m ; i ++ ){
        opt = read() , l = read() , r = read();
        if( opt == 1 ) modify( l , r , read() , root );
        else printf("%lld\n" , query( l , r , root ) );
    }
    return 0;
}