#include <bits/stdc++.h>
class Solution {
public:
    bool isPalindrome(string s) {
        
        int i=0,j=s.size()-1;
        while(i<j){
            cout<<"a: "<<s[i]<<" "<<s[j]<<endl;
            if(s[i]>='A' && s[i]<='Z'){
                char lower = s[i] + ('a' - 'A'); 
                s[i]=lower;
            }
            if(s[j]>='A' && s[j]<='Z'){
                char lower = s[j] + ('a' - 'A'); 
                s[j]=lower;
            }
            if(((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) && ((s[j]>='a' && s[j]<='z') || (s[j]>='0' && s[j]<='9'))){
                if(s[i]!=s[j])  return 0;
                i++;
                j--;
            }
            else{
                if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
                    j--;
                }
                else if((s[j]>='a' && s[j]<='z') || (s[j]>='0' && s[j]<='9')){
                    i++;
                }
                else{
                    i++;
                    j--;
                }
            }
            cout<<"b: "<<s[i]<<" "<<s[j]<<endl;
        }
        return 1;
    }
};