class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())  return false;
        map<char,char> mp1;
        map<char,int> mp2;
        string x="";
        int i=0;
        while(i<s.size()){
            // if(s[i]==t[i]){
            //     x.push_back(s[i]);
            //     i++;
            //     continue;
            // }
            if(mp1.find(s[i])==mp1.end()){
                if(mp2.find(t[i])!=mp2.end())   return false;
                mp1[s[i]]=t[i];
                mp2[t[i]]++;
            }
            x.push_back(mp1[s[i]]);
            i++;
        }
        return x==t;
    }
};