class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int i=0, score=0;
        while(i<s.size()){
            if(s[i]=='('){
                st.push(score);
                score=0;
            }
            else{
                if(s[i-1]=='('){
                    score=st.top()+1;
                }
                else{
                    score=score*2+st.top();
                }
                st.pop();
            }
            i++;
        }
        return score;
    }
};