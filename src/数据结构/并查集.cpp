// 初始化
for( int i = 1 ; i <= n ; i ++ ) fa[i] = i;
// 查找
int getFa( int x ){
    if( fa[x] == x ) return x;
    return fa[x] = getFa( fa[x] );
}
// 合并
void merge( int x , int y ){
    fa[getFa(x) ] = getFa(y);
}

/*
 * 下面是一种按秩合并的写法
 * 简单来说fa[x]<0表示该点为根结点，当x为根节点时 fa[x] = -size[x]
 */
class dsu{
private:
    vector<int> fa;
public:
    dsu( int n = 1 ){
        fa = vector<int>( n+1 , -1 ) , fa[0] = 0;
    }
    int getfa( int x ){
        if( fa[x] < 0 ) return x;
        return fa[x] = getfa( fa[x] );
    }
    void merge( int x , int y ){
        x = getfa(x) , y = getfa(y);
        if( x == y ) return ;
        if( fa[x] > fa[y] ) swap( x , y );
        fa[x] += fa[y] , fa[y] = x;
    }
    bool check( int x , int y ){
        x = getfa(x) , y = getfa(y);
        return ( x == y );
    }
};