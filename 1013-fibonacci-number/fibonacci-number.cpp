class Solution {
public:
    int helper(int n, vector<int> & dp){
        if(n==0)      return 0;
        else if(n==1)   return 1;
        if(dp[n]!=-1)   return dp[n];
        return (dp[n]=helper(n-1,dp)+helper(n-2,dp));
    }
    int fib(int n) {
        if(n==0)      return 0;
        else if(n==1)   return 1;
        vector<int> dp(n+1,-1);
        helper(n, dp);
        return dp[n];
    }
};