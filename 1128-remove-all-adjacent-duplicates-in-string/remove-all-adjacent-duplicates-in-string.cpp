class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(char x:s){
            if(st.empty())  st.push(x);
            else{
                if(st.top()==x){
                    st.pop();
                }
                else    st.push(x);
            }
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};