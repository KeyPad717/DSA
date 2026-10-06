class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0, close=0, i=0;
        int count=0, sum=0;

        while(i<s.size()){
            if(s[i]=='('){
                open++;
            }
            else{
                if(open==0)            close++;
                else if(open>0)   open--;
            }
            i++;
        }
        return open+close;
    }
};