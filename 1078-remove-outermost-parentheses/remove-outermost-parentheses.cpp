class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string ans="";
        for(char x:s){
            if(cnt==0)  cnt++;
            else{
                if(x==')'){
                    cnt--;
                    if(cnt==0){
                        continue;
                    }  
                    ans.push_back(')');
                }  
                else{
                    cnt++;
                    ans.push_back('(');
                }
            }
        }
        return ans;
    }
};