class Triangle{
    typedef std::pair<int,int> Vector;
private:
    Vector getVector( int x , int y , int a , int b ){
        return std::pair{ a - x , b - y };
    }
    bool product( Vector a , Vector b ){
        return ( a.first * b.second - a.second * b.first ) > 0;
    }
public:
    int ax , ay , bx ,by , cx , cy;
    Vector ab , bc , ca;
    Triangle( int ax , int ay , int bx , int by , int cx , int cy ):
            ax(ax) , ay(ay) , bx(bx) , by(by) , cx(cx) , cy(cy) ,
            ab( getVector( ax , ay , bx , by ) ),
            bc( getVector( bx , by , cx , cy ) ),
            ca( getVector( cx , cy , ax , ay ) ){};
    Triangle(){};
    bool isInTriangle( int x , int y ){
        Vector ao = getVector( ax , ay , x , y );
        Vector bo = getVector( bx , by , x , y );
        Vector co = getVector( cx , cy , x , y );
        bool f1 = product( ao , ab ) , f2 = product( bo , bc ) , f3 = product( co , ca );
        return ( f1 == f2 && f2 == f3 );
    }
};