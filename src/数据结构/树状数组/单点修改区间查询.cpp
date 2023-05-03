struct BinaryIndexedTree{
#define lowbit(x) ( x & -x )
    int n;
    vector<int> b;

    BinaryIndexedTree( int n ) : n(n) , b(n+1 , 0){};
    BinaryIndexedTree( vector<int> &c ){ // 注意数组下标必须从 1 开始
        n = c.size() , b = c;
        for( int i = 1 , fa = i + lowbit(i) ; i <= n ; i ++ , fa = i + lowbit(i) )
            if( fa <= n ) b[fa] += b[i];
    }
    void add( int i , int y ){
        for( ; i <= n ; i += lowbit(i) ) b[i] += y;
        return;
    }

    int calc( int i ){
        int sum = 0;
        for( ; i ; i -= lowbit(i) ) sum += b[i];
        return sum;
    }
};
};