class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        for( int x: asteroids){
            if(st.empty())  st.push(x);
            else{
                if(x>0){
                    st.push(x);
                }
                else{
                    int f=0;
                    while(!st.empty() && st.top()>0){
                        if(st.top()==abs(x)){
                            f++;
                            st.pop();
                            break;
                        }
                        else if(abs(st.top())<abs(x))  st.pop();   
                        else{
                            break;
                        }                   
                    }
                    if(st.empty() && f==0)  st.push(x);
                    else if(f==0){
                        if(st.top()<0)  st.push(x);
                    }
                }
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};