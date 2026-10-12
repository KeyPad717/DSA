class Solution {
public:
    int longestValidParentheses(string s) {
        int i=0, open=0, close=0;
        int maxi=0;
        while(i<s.size()){
            if(s[i]=='('){
                open++;
            }
            else{
                close++;
            }
            if(close>open){
                close=0;
                open=0;
            }
            else if(close==open){
                maxi=max(maxi, open*2);
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
                close=0;
                open=0;
            }
            else if(close==open){
                maxi=max(maxi, open*2);
            }
            i--;
        }
        return maxi;
    }
};