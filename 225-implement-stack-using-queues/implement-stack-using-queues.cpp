class MyStack {
public:
    queue<int> dq;
    MyStack() {
        
    }
    
    void push(int x) {
        dq.push(x);
    }
    
    int pop() {
        int z=dq.back();
        int sz=dq.size();
        for(int i=0;i<sz-1;i++){
            int temp=dq.front();
            dq.pop();
            dq.push(temp);
        }
        dq.pop();
        return z;
    }
    
    int top() {
        int x=dq.back();
        return x;
    }
    
    bool empty() {
        return dq.empty();
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