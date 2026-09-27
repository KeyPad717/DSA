class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int idx=0;
        int i=0;
        while(i<s.size()){
            if(s[i]=='('){
                st.push(i);
                idx++;
            }
            else if(s[i]==')'){
                int j=st.top();
                reverse(s.begin()+j+1, s.begin()+i);
                st.pop();
                s.erase(s.begin()+i);
                s.erase(s.begin()+j);
                i-=2;
            }
            i++;
        }
        return s;
    }
};