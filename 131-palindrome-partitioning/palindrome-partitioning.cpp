class Solution {
public:
    bool isPal(string s){
        if(s=="")   return false;
        string y=s;
        reverse(y.begin(),y.end());
        return y==s;
    }
    void helper(int idx, string s, vector<vector<string>>& res, vector<string>& res1){
        if(idx==s.size()){
            res.push_back(res1);
            return ;
        }
        for(int i=idx;i<s.size();i++){
            string temp=s.substr(idx,i-idx+1);
            if(isPal(temp)){
                res1.push_back(temp);
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