class MyStack {
private:
    deque<int> st;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        st.push_back(x);
    }
    
    int pop() {
        int node;
        if(st.size()>0) {
            node = st.back();
            st.pop_back();
            return node;
        }
        return -1;
        
    }
    
    int top() {
        if(st.size()>0) {
            int node = st.back();
            return node;
        }
        return -1;
        
    }
    
    bool empty() {
        return st.empty();
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