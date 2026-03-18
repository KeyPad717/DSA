class Solution {
public:
    int solver(int n, vector<int>& dp){
        if(n==0)    return(dp[n]=0);
        if(n==1)    return(dp[n]=1);
        if(dp[n]!=-1)   return dp[n];
        return dp[n]=solver(n-1,dp)+solver(n-2,dp);
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return solver(n,dp);
        // if(n==0)    return 0;
        // if(n==1)    return 1;
        // return(fib(n-1)+fib(n-2));
    }
};