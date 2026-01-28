class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(),len1=0,len2=0;
        map<char,int> mp;
        int i=0,j=0;
        while(j<n){
            mp[s[j]]++;
            if(mp.size()==3){
                // if(j==n-1){
                //     len1++;
                //     break;
                // }
                while(mp.size()==3 && i<n){
                    len1+=n-j;
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
                //cout<<i<<" "<<s[i]<<" "<<j<<" "<<s[j]<<" "<<len1<<endl;
                
                //cout<<i<<" "<<s[i]<<" "<<j<<" "<<s[j]<<" "<<len1<<endl;
            }
            j++;
        }
        i=n-1;
        j=n-1;
        mp.clear();
        while(j>-1){
            mp[s[j]]++;
            if(mp.size()==3){
                // if(j==0){
                //     len2++;
                //     break;
                // }
                while(mp.size()==3 && i<n){
                    len2+=1+j;
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i--;
                }
            }
            j--;
        }
        //cout<<len1<<" "<<len2;
        return max(len1,len2);
    }
};