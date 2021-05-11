class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> st;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        int n = st.size();
        st.push(x);
        if(n == 0)return;
        while(n--){
            int t = st.front();
            st.pop();st.push(t);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if( !st.empty() ){
            int t = st.front();
            st.pop();return t;
        }
        return 0;
    }
    
    /** Get the top element. */
    int top() {
        if( !st.empty() ){
            int t = st.front();
            return t;
        }
        return 0;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(st.size() == 0){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
