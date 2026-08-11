class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string str="", ans="";
        int i=0,j=0;
        while(i<s.size() && s[i]==' '){
            i++;
        }
        while(i<s.size() && j<s.size()){
            if(s[j]==' '){
                while(j<s.size() && s[j]==' '){
                    j++;
                }
                //cout<<str<<endl;
                if(ans=="") ans=str;
                else    ans=str+' '+ans;
                str="";
                i=j;
                j=i;
            }
            else{
                str.push_back(s[j]);
                j++;
            }
        }
        if(str!="") ans=str+' '+ans;
        if(ans[ans.size()-1]==' ')  ans.pop_back();
        return ans;
    }
};