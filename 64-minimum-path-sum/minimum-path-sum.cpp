class Solution {
public:
    int helper(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(x<0 || y<0)      return INT_MAX;
        if(x==0 && y==0)    return grid[x][y];
        if(dp[x][y]!=-1)    return dp[x][y];
        int up=0, left=0;
        if(x>=0)    up=helper(x-1,y,grid,dp);
        if(y>=0)    left=helper(x,y-1,grid,dp);
        if(up==INT_MAX && left==INT_MAX)    dp[x][y]=grid[x][y];
        else if(up==INT_MAX)                dp[x][y]=grid[x][y]+left;
        else if(left==INT_MAX)              dp[x][y]=grid[x][y]+up;
        return dp[x][y]=grid[x][y]+min(up,left);    
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return helper(m-1,n-1,grid,dp);
    }
};