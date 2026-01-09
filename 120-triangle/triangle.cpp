class Solution {
public:
    // int solver(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp){
    //     if(i==n)    return triangle[i][j];
    //     if(dp[i][j]!=-1)    return dp[i][j];
    //     dp[i][j]=triangle[i][j]+min(solver(i+1,j,n,triangle,dp),solver(i+1,j+1,n,triangle,dp));
    //     return dp[i][j];
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        for(int i=0;i<n;i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};