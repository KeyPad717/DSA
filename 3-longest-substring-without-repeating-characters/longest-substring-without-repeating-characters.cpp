class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        map<char,int> mp;
        int i=0,j=0,maxi=0;
        if(s==" ")  return 1;
        if(s.size()==1) return 1;
        while(i<n && j<n){
            mp[s[j]]++;
            if(mp[s[j]]>1){
                maxi=max(maxi,j-i);
                while(mp[s[j]]>1){
                    mp[s[i]]--;
                    i++;
                }
                j++;
            }
            else{
                maxi=max(maxi,j-i+1);
                j++;
            }
        }
        return maxi;
    }
};