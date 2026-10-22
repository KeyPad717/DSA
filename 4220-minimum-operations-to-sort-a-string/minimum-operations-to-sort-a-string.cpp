class Solution {
public:
    int minOperations(string s) {
        bool sorted=true;
        for(int i=1;i<s.size();i++){
            if(s[i]<s[i-1]){
                sorted=false;
                break;
            }
        }
        if(sorted)  return 0;
        if(s.size()==2)   return -1;
        char mini='z', maxi='a';
        char max_mid='a', min_mid='z';
        int min_idx=-1, max_idx=-1;
        for(int i=0;i<s.size();i++){
            if(i>0 && i<s.size()-1){
                if(max_mid<s[i]){
                    max_mid=s[i];
                }
                if(min_mid>s[i]){
                    min_mid=s[i];
                }
            }
            if(s[i]<=mini){
                mini=s[i];
                min_idx=i;
            }
             if(s[i]>=maxi){
                maxi=s[i];
                max_idx=i;
            }
        }
        if(mini==s[0] || maxi==s[s.size()-1])   return 1;
        if(s[0]>max_mid && min_mid>s[s.size()-1])   return 3;
        return 2;
    }
};