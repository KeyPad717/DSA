class Solution {
public:
    bool isIsomorphic(string s, string t) {
    if (s.size() != t.size())
        return false;

    unordered_map<char, char> mp1;
    unordered_set<char> used;

    for (int i = 0; i < s.size(); i++) {
        if (mp1.find(s[i]) == mp1.end()) {
            if (used.find(t[i]) != used.end())
                return false;
            mp1[s[i]] = t[i];
            used.insert(t[i]);
        }
        else{
            if(t[i]!=mp1[s[i]]) return false;
        }
    }

    return true;
}
    // bool isIsomorphic(string s, string t) {
    //     if(s.size()!=t.size())  return false;
    //     map<char,char> mp1;
    //     vector<int> mp2(256,0);
    //     string x="";
    //     int i=0;
    //     while(i<s.size()){
    //         if(mp1.find(s[i])==mp1.end()){
    //             if(mp2[t[i]]!=0)   return false;
    //             mp1[s[i]]=t[i];
    //             mp2[t[i]-'0']++;
    //         }
    //         x.push_back(mp1[s[i]]);
    //         i++;
    //     }
    //     return x==t;
    // }
};