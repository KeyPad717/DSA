class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v1(26),v2(26);
        for(char x:s){
            v1[x-'a']++;
        }
        for(char x:t){
            v2[x-'a']++;
        }
        return v1==v2;
    }
};