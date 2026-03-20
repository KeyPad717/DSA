#include <bits/stdc++.h>
class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ')  {
                if(s[i]>='A' && s[i]<='Z'){
                    char lower = s[i] + ('a' - 'A'); 
                    s[i]=lower;
                }
                else if(s[i]>='a' && s[i]<='z'){
                    s[i]=s[i];
                }
                else if(s[i]>='0' && s[i]<='9'){
                    s[i]=s[i];
                }
                else{
                    s.erase(i,1);
                    i--;
                }
            }
            else{
                s.erase(i,1);
                i--;
            }
        }
        cout<<s<<endl;
        //reverse(s1.begin(),s1.end());
        //if(s1==s2)  return 1;
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]==' ')   i++;
            if(s[j]==' ')   j--;
            cout<<s[i]<<" "<<s[j]<<endl;
            if(s[i]!=s[j])  return 0;
            i++;
            j--;
        }
        return 1;
    }
};