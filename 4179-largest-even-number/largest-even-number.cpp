class Solution {
public:
    string largestEven(string s) {
        int n=s.size();
        int idx=-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='2'){
                idx=i;
                break;
            }
        }
        if(idx==-1) return "";
        return s.substr(0,idx+1);
    }
};