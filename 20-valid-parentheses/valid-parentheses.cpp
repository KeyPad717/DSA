class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char x:s){
            if(x=='{' || x=='(' || x=='['){
                st.push(x);
            }
            else if(st.empty())  return false;
            else{
                if(x==')'){
                    if (st.top()=='('){
                        st.pop();
                    }
                    else   return false; 
                }
                else if(x=='}'){
                    if (st.top()=='{'){
                        st.pop();
                    }
                    else   return false; 
                }
                else{
                    if (st.top()=='['){
                        st.pop();
                    }
                    else   return false; 
                }
            }
        }
        if(st.empty())  return true;
        return false;
    }
};