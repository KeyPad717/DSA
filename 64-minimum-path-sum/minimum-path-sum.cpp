class Solution {
public:
    int solver(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp){
        if(m==0 && n==0) return grid[0][0];
        if(dp[m][n]!=-1)    return dp[m][n];
        if(m==0){
            dp[m][n]=grid[m][n]+solver(grid,m,n-1,dp);
            return dp[m][n];
        }
        if(n==0){
            dp[m][n]=grid[m][n]+solver(grid,m-1,n,dp);
            return dp[m][n];
        }
        dp[m][n]=grid[m][n]+min(solver(grid,m,n-1,dp),solver(grid,m-1,n,dp));
        return dp[m][n];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return(solver(grid,m-1,n-1,dp));
    }
};