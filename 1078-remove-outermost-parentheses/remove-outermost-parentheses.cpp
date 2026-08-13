class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans="";
        for(char x:s){
            if(st.empty())  st.push(x);
            else{
                if(x==')'){
                    st.pop();
                    if(st.empty())  continue;
                    ans.push_back(')');
                }  
                else{
                    st.push(x);
                    ans.push_back('(');
                }
            }
        }
        return ans;
    }
};