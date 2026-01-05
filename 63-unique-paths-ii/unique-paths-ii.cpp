class Solution {
public:
    int solver(vector<vector<int>>& obstacleGrid, int m, int n, vector<vector<int>>& dp){
        if(obstacleGrid[m][n]==1){
            return 0;
        }
        if(m==0 && n==0)    return 1;
        if(dp[m][n]!=-1)    return dp[m][n];
        if(m==0){
            dp[m][n]=solver(obstacleGrid,m,n-1,dp);
            return dp[m][n];
        }
        if(n==0){
            dp[m][n]=solver(obstacleGrid,m-1,n,dp);
            return dp[m][n];
        }
        dp[m][n]=solver(obstacleGrid,m-1,n,dp)+solver(obstacleGrid,m,n-1,dp);
        return dp[m][n];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(m==1 && n==1){
            if(obstacleGrid[0][0]==0)  return 1;
            if(obstacleGrid[0][0]==1)  return 0; 
        }
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return(solver(obstacleGrid,m-1,n-1,dp));
    }
};