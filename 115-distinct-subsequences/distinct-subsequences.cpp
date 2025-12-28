class Solution {
public:
    int solver(string s, string t, int n, int m, vector<vector<int>> &dp){
        if(m==0) return 1;
        if(n==0) return 0;
        if(dp[n][m]!=-1)    return dp[n][m];
        if(s[n-1]==t[m-1]){
            dp[n][m]=solver(s,t,n-1,m-1,dp)+solver(s,t,n-1,m,dp);
            return dp[n][m];
        }
        dp[n][m]=solver(s,t,n-1,m,dp);
        return dp[n][m];
    }
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return(solver(s,t,n,m,dp));
    }
};