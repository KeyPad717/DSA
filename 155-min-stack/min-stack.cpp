class MinStack {
public:
    stack<int> st, minst;
    map<int,int> mp;
    MinStack() {
        
    }
    void push(int value) {
        st.push(value);
        mp[value]++;
    }
    
    void pop() {
        int val=st.top();
        st.pop();
        mp[val]--;
        if(mp[val]==0)  mp.erase(val);
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        auto fir=mp.begin();
        return fir->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */