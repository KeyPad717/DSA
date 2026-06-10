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
        vector<int> v;
        int n=dq.size(), sz=dq.size();
        while(!empty() && n>=0){
            int y=dq.front();
            v.push_back(y);
            n--;
            dq.pop();
        }
        //for(int i=0;i<v.size();i++) cout<<v[i]<<endl;
        dq=queue<int>();
        for(int i=0;i<sz-1;i++){
            dq.push(v[i]);
        }
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