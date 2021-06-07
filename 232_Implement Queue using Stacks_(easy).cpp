class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> a;
    stack<int> b;
    int Top;
    
    /** Push element x to the back of queue. */
    void push(int x) {
        a.push(x);
        if( a.size() == 1 ){
            Top = x;
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if( !b.empty() ){
            int temp = b.top();
            b.pop();
            return temp;
        }
        else if( !a.empty() ){
            while( !a.empty() ){
                int temp = a.top();
                a.pop();
                b.push(temp);
            }
            int temp = b.top();
            b.pop();
            return temp;
        }
        return 0;
    }
    
    /** Get the front element. */
    int peek() {
        if( !b.empty() ){
            return b.top();
        }
        else if( !a.empty() && Top != -1 ){
            return Top;
        }
        return 0;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if( a.empty() && b.empty() ){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
