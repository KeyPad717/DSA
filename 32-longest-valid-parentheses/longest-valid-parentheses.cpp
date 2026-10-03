class Solution {
public:
    int longestValidParentheses(string s) {
        int maxi=0;
        int open=0, close=0;
        int i=0;
        while(i<s.size()){
            if(s[i]=='('){
                open++;
            }
            else{
                close++;
            }
            if(close>open){
                open=0;
                close=0;
            }
            else if(close==open){
                maxi=max(maxi,close+open);
            }
            i++;
        }
        i=s.size()-1;
        open=0;
        close=0;
        while(i>=0){
            if(s[i]=='('){
                open++;
            }
            else{
                close++;
            }
            if(open>close){
                open=0;
                close=0;
            }
            else if(close==open){
                maxi=max(maxi,close+open);
            }
            i--;
        }
        return maxi;
    }
};