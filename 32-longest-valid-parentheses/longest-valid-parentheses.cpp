class Solution {
public:
    int longestValidParentheses(string s) {
        int open=0, close=0, cnt=0, maxi=0;
        int i=0;
        while(i<s.size()){
            if(s[i]=='('){
                open++;
            }
            else{
                close++;
                if(close>open){
                    maxi=max(maxi,open*2);
                    open=0;
                    close=0;
                }
                else if(close==open){
                    maxi=max(maxi,open*2);
                }
            }
            i++;
        }
        open=0;
        close=0;
        cnt=0;
        i=s.size()-1;
        while(i>=0){
            if(s[i]==')'){
                close++;
            }
            else{
                open++;
                if(open>close){
                    maxi=max(maxi,close*2);
                    open=0;
                    close=0;
                }
                else if(close==open){
                    maxi=max(maxi,open*2);
                }
            }
            i--;
        }
        return maxi;
    }
};