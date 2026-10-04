class Solution {
public:
    bool helper(int idx, int open, int close, string& s, vector<vector<vector<int>>>& dp){
        if(idx==s.size()){
            if(open==close) return true;
            else            return false;
        }
        if(close>open)  return false;
        if(dp[idx][open][close]!=-1)    return dp[idx][open][close];
        if(s[idx]=='('){
            return dp[idx][open][close]=helper(idx+1, open+1, close, s, dp);
        }
        else if(s[idx]==')'){
            return dp[idx][open][close]=helper(idx+1, open, close+1, s, dp);
        }
        else{
            return dp[idx][open][close]=helper(idx+1, open+1, close, s, dp) || helper(idx+1, open, close+1, s, dp) || helper(idx+1, open, close, s, dp);
        }
    }
    bool checkValidString(string s) {
        vector<vector<vector<int>>> dp(s.size()+1, vector<vector<int>>(s.size(), vector<int> (s.size(),-1)));
        return helper(0, 0, 0, s, dp);
    }
};