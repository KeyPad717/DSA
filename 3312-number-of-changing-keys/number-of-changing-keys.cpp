class Solution {
public:
    int countKeyChanges(string s) {
        for(char &x:s){
            x=tolower(x);
        }
        int cnt=0;
        for(int i=1;i<s.size();i++){
            if(s[i]!=s[i-1])    cnt++;
        }
        return cnt;
    }
};