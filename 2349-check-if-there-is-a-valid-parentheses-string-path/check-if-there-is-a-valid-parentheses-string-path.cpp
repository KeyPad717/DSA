class Solution {
public:
    bool helper(int i, int j, vector<vector<char>>& grid, int num1, vector<vector<vector<int>>>& dp){
        if(i>=grid.size() || j>=grid[0].size()){
            return false;
        }
        if(dp[i][j][num1]!=-1)  return dp[i][j][num1];
        if(i==grid.size()-1 && j==grid[0].size()-1){
            if(num1==1) return grid[i][j]==')';
        }
        if(grid[i][j]=='('){
            return dp[i][j][num1]=helper(i+1,j,grid, num1+1, dp) || helper(i,j+1,grid, num1+1,dp);
        }
        if(num1<=0)  return dp[i][j][num1]=false;
        return dp[i][j][num1]=helper(i+1,j, grid, num1-1,dp) || helper(i,j+1,grid, num1-1,dp);
        
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m+n+1,-1)));
        if(grid[0][0]==')'){
            return false;
        }
        return helper(0,0, grid, 0,dp);
    }
};