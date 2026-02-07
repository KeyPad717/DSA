#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size(),l=0,r=0,maxf=0,len=0,maxi=0;
        map<int,int> mp;
        while(l<n && r<n){
            mp[s[r]-'A']++;
            maxf=max(maxf,mp[s[r]-'A']);
            int rem=r-l+1-maxf;
            if(rem<=k){
                maxi=max(maxi,r-l+1);
                //cout<<l<<" "<<s[l]<<" "<<r<<" "<<s[r]<<" "<<maxi<<endl;
            }
            else{
                mp[s[l]-'A']--;
                l++;
            }
            r++;
        }
        return maxi;
    }
};