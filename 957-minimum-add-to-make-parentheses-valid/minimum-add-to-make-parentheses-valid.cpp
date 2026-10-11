class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0, close=0;
        int i=0, cnt=0, res=0;
        while(i<s.size()){
            if(s[i]=='('){
               cnt++;
            }
            else{
                if(cnt>0){
                    cnt--;
                }
                else{
                    res++;
                }
            }
            i++;
        }
        return res+cnt;
    }
};