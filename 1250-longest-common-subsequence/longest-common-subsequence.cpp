class Solution {
public:
    int helper(int n, int m, string& text1, string& text2, vector<vector<int>>& dp){
        if(n==0 || m==0)    return 0;
        if(dp[n][m]!=-1)    return dp[n][m];
        if(text1[n-1]==text2[m-1]){
            return dp[n][m]=1+helper(n-1, m-1, text1, text2,dp);
        }
        return dp[n][m]=max(helper(n-1,m,text1,text2,dp),helper(n,m-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, -1));
        return helper(text1.size(), text2.size(), text1, text2,dp);
    }
};