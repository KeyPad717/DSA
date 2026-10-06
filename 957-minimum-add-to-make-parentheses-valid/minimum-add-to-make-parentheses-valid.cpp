class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0, close=0, i=0;
        int count=0, sum=0;
        stack<char> st;
        while(i<s.size()){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(st.empty())            st.push(s[i]);
                else if(st.top()=='(')   st.pop();
                else                st.push(s[i]);
            }
           // cout<<i<<" "<<s[i]<<" "<<st.top()<<endl;
            i++;
        }
        return st.size();
    }
};