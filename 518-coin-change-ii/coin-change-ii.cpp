class Solution {
public:
    int solver(int k, vector<int>& coins, int n,vector<vector<int>> &dp){
        if(k==0)    return 1;
        if(n==0)    return 0;
        if(dp[n][k]!=-1)    return dp[n][k];
        if(coins[n-1]<=k){
            dp[n][k]=solver(k-coins[n-1],coins,n,dp)+solver(k,coins,n-1,dp);
            return(dp[n][k]);
        }
        dp[n][k]=solver(k,coins,n-1,dp);
        return(dp[n][k]);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));
        return(solver(amount, coins, n,dp));
    }
};