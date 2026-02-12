class Solution {
public:
    string reverseByType(string s) {
        if(s.size()==0) return " ";
        string s1="",s2="",s3="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(int(s[i])>=97 && int(s[i])<=122){
                s1+=s[i];
            }
            else{
                s2+=s[i];
            }
        }
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        if(s1.size()==0 && s2.size()==0)    return "";
        if(s1.size()==0)    return s2;    
        if(s2.size()==0)    return s1; 
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if(int(s[i])>=97 && int(s[i])<=122){
                s3+=s1[x];
                x++;
            }
            else{
                s3+=s2[y];
                y++;
            }
        }
        return s3;
    }
};