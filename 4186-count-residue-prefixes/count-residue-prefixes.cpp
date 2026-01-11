class Solution {
public:
    int residuePrefixes(string s) {
        int n=s.size();
        if(n==1)      return 1;
        if(n==2){
            if(s[0]==s[1])      return 1;
            else                return 2;
        }
        map<char,int> mp;
        int c=0;
        for(int i=0;i<n;i++){
            if(mp[s[i]]!=1)    mp[s[i]]++;
            if(((i+1)%3)==mp.size()) c++;
            //cout<<i<<" "<<mp.size();
        }
        return c;
    }
};