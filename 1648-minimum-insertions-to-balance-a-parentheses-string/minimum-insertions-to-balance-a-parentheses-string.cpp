class Solution {
public:
    int minInsertions(string s) {
        int i=0, cnt=0, ans=0;
        while(i<s.size()){
            if(s[i]=='('){
                cnt++;
                i++;
            }
            else{
                if(cnt>0){
                    cnt--;
                }
                else{
                    ans++;
                }
                if(i<s.size()-1 && s[i+1]==')'){
                    i=i+2;
                }
                else{
                    ans+=1;
                    i++;
                }
            }
        }
        return ans+cnt*2;
    }
};