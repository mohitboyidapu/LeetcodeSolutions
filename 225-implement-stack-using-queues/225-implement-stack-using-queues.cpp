class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        for(int i=0; i<q.size()-1; i++){
            q.push(q.front());
            q.pop();
        }
        int node = q.front();
        q.pop();
        return node;
        
    }
    
    int top() {
        for(int i=0; i<q.size()-1; i++){
            q.push(q.front());
            q.pop();
        }
        int node = q.front();
        q.push(node);
        q.pop();
        return node;
        
    }
    
    bool empty() {
        return q.empty();
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