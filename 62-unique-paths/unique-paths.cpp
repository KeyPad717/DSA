class Solution {
public:
    int solver(int m, int n, vector<vector<int>> &dp){
        if(m==0 && n==0)    return 1;
        if(dp[m][n]!=-1)    return dp[m][n];
        if(m==0){
            dp[m][n]=solver(m,n-1,dp);
            return(dp[m][n]);
        }
        if(n==0){
            dp[m][n]=solver(m-1,n,dp);
            return(dp[m][n]);
        }
        dp[m][n]=solver(m-1,n,dp)+solver(m,n-1,dp);
        return(dp[m][n]);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return(solver(m-1,n-1,dp));
    }
};