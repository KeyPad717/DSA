class Solution {
public:
    int solver(int k, vector<int>& coins, int n,vector<vector<int>> &dp){
        if(n==0){
            if(k%coins[n]==0) return k/coins[n];
            else return 1e9;
        }
        if(dp[n][k]!=-1)    return dp[n][k];
        int notTake=0+solver(k,coins,n-1,dp);
        int Take=INT_MAX;
        if(coins[n-1]<=k){
            Take=1+solver(k-coins[n-1],coins,n,dp);
        }
        return(dp[n][k]=min(Take,notTake));
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));
        int out = solver(amount, coins, n,dp);
        if(out==1e9)    return -1;
        else            return out;
    }
};