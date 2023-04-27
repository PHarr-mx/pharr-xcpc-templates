// 离散化差分这里我用map实现
map<int,int> b;

void update( int l , int r , int v ){
    b[l] += v , b[r+1] -= v;
}

// 求和
for( auto it = b.begin() ; next(it) != b.end() ; it = next(it) )
    next(it)->second += it->second;