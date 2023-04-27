struct MinStack{
    stack<int> a , b;
    void push( int x ){
        a.push(x);
        if( b.size() ) b.push( min( x , b.top() ) );
        else b.push(x);
    }
    void pop(){
        a.pop() , b.pop();
    }
    int top(){
        return a.top();
    }
    int getMin(){
        return b.top();
    }
};