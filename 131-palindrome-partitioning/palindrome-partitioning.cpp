class Solution {
public:
    bool isPal(int l, int r,const string& s){
        while(l<=r){
            if(s[l++]!=s[r--])  return false;
        }
        return true;
    }
    void helper(int idx, string s, vector<vector<string>>& res, vector<string>& res1){
        if(idx==s.size()){
            res.push_back(res1);
            return ;
        }
        for(int i=idx;i<s.size();i++){
            if(isPal(idx, i, s)){
                res1.push_back(s.substr(idx,i-idx+1));
                helper(i+1,s,res,res1);
                res1.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> res1;
        helper(0,s,res,res1);
        return res;
    }
};