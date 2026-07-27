class Solution {
public:
    int helper(int x, int y, const vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        if(x<0 || y<0)  return 0;
        if(obstacleGrid[x][y]==1)   return 0;
        if(x==0 && y==0)    return 1;
        if(dp[x][y]!=-1)    return dp[x][y];
        return dp[x][y]=helper(x-1,y,obstacleGrid,dp) + helper(x,y-1,obstacleGrid,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int> (n));
        if(obstacleGrid[0][0]==1) return 0;
        else                       dp[0][0]=1;
        for(int i=1;i<m;i++){
            if(obstacleGrid[i][0]==1 || dp[i-1][0]==0){
                dp[i][0]=0;
            }   
            else                        dp[i][0]=1;
        }
        for(int i=1;i<n;i++){
            if(obstacleGrid[0][i]==1 || dp[0][i-1]==0){
                dp[0][i]=0;
            } 
            else                        dp[0][i]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1)   dp[i][j]=0;
                else                        dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};