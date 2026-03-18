#include <bits/stdc++.h>
class Solution {
public:
    bool isPalindrome(string s) {
        string s1="",s2="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ')  {
                if(s[i]>='A' && s[i]<='Z'){
                    char lower = s[i] + ('a' - 'A'); 
                    s1 += lower;
                    s2 += lower;
                }
                else if(s[i]>='a' && s[i]<='z'){
                    s1+=s[i];
                    s2+=s[i];
                }
                else if(s[i]>='0' && s[i]<='9'){
                    s1+=s[i];
                    s2+=s[i];
                }
                // s1+=s[i].lower();
                // s2+=s[i].lower();
            }
        }
        reverse(s1.begin(),s1.end());
        cout<<s1<<endl;
        cout<<s2<<endl;
        if(s1==s2)  return 1;
        return 0;
    }
};