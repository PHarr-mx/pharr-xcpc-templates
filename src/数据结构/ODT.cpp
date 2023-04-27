class ODT{
private:
    struct Node{ // 节点存储结构
        int l , r;
        mutable int val;
        Node( int l , int r = 0 , int val = 0 ) :
                l(l) , r(r) , val(val){};
        bool operator < ( Node b ) const {
            return l < b.l;
        }
        int len() const{
            return r - l + 1;
        }
    };
    int len;
    set<Node> s;
public:
    // 两种构造函数
    ODT( const int & n , const vector<int> & a ){
        len = n;
        int t = 1;
        for( int v : a )
            s.insert( Node( t , t , v ) ) , t ++;
    }
    ODT( const int & n , const int a[] ){
        len = n;
        for( int i = 1 ; i <= n ; i ++ )
            s.insert( Node( i , i , a[i] ) );
    }

    auto split( int x ){ // 区间分裂
        if( x > len ) return s.end();
        auto it = --s.upper_bound( Node( x ) );
        if( it->l == x ) return it;
        int l = it->l , r = it->r , v = it->val;
        s.erase(it);
        s.insert( Node( l , x-1 , v ) );
        return s.insert( Node( x , r , v ) ).first;
    }
    void assign( int l , int r , int v ){ // 区间赋值 平推操作
        auto itr = split( r + 1 ) , itl = split( l );
        s.erase( itl , itr );
        s.insert( Node( l , r , v ) );
    }
    void add( int l , int r , int x ){ // 区间修改
        auto itr = split( r+1 ) , itl = split( l );
        for( auto it = itl ; it != itr ; it ++ )
            it->val +=x;
    }
    int rank( int l , int r , int x ){ // 求区间第 x 大
        auto itr = split(r+1) , itl = split(l);
        vector< pair<int,int> > v; // first 表示 num , second 表示 cnt
        for( auto it = itl ; it != itr ; it ++ )
            v.push_back({ it->val , it->len() } );
        sort( v.begin() , v.end() );
        for( auto [ num , cnt ] : v ){
            if( cnt < x ) x -= cnt;
            else return num;
        }
    }
    void merge( int l , int r ){ // 区间合并 推平
        auto itr = split(r+1) , itl = split(l);
        vector<Node> cur;
        for( auto it = itl ; it != itr ; it ++ ){
            if( cur.empty() || it->val != cur.back().val )
                cur.push_back( *it );
            else cur.back().r = it->r;
        }
        s.erase( itl , itr );
        for( auto it : cur )
            s.insert( it );
        return;
    }
    int calP( int l , int r , int x , int y ){ // 求区间 x 次方之和
        auto itr = split(r+1) , itl= split(l);
        int ans = 0;
        for( auto it = itl ; it != itr ; it ++ )
            ans = ( ans + power(it->val,x,y) * it->len()%y ) % y;
        return ans % y;
    }
};
