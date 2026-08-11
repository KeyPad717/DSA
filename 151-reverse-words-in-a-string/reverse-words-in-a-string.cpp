class Solution {
public:
    string reverseWords(string s) {
        string str="", ans="";
        int j=0;
        while(j<s.size()){
            if(s[j]==' '){
                while(j<s.size() && s[j]==' '){
                    j++;
                }
                if(ans=="") ans=str;
                else    ans=str+' '+ans;
                str="";
            }
            else{
                str.push_back(s[j]);
                j++;
            }
        }
        if(str!="") ans=str+' '+ans;
        if(ans!="" && ans[ans.size()-1]==' ')  ans.pop_back();
        return ans;
    }
};