class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        for(string str:strs){
            string temp=str;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(str);
        }
        for(auto x:mp){
            vector<string> temp1;
            for(auto y:x.second){
                temp1.push_back(y);
            }
            ans.push_back(temp1);
        }
        return ans;
    }
};