class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> arr1(26), arr2(26);
        for(char x:s){
            arr1[x-'a']++;
        }
        for(char x:t){
            arr2[x-'a']++;
        }
        return arr1==arr2;
    }
};