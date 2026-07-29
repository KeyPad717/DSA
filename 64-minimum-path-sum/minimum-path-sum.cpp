class Solution {
public:
    int helper(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(x<0 || y<0)      return INT_MAX;
        if(x==0 && y==0)    return grid[x][y];
        if(dp[x][y]!=-1)    return dp[x][y];
        int up=helper(x-1,y,grid,dp);
        int left=helper(x,y-1,grid,dp);
        if(up==INT_MAX)                return dp[x][y]=grid[x][y]+left;
        else if(left==INT_MAX)              return dp[x][y]=grid[x][y]+up;
        return dp[x][y]=grid[x][y]+min(up,left);    
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n));
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)    continue;
                int up=INT_MAX, down=INT_MAX;
                if(i>0) up=dp[i-1][j];
                if(j>0) down=dp[i][j-1];
                dp[i][j]=grid[i][j]+min(up,down);
            }
        }
        return dp[m-1][n-1];
    }
};