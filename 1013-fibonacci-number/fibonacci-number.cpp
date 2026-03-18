class Solution {
public:
    // int solver(int n, vector<int>& dp){
    //     if(n==0)    return(dp[n]=0);
    //     if(n==1)    return(dp[n]=1);
    //     if(dp[n]!=-1)   return dp[n];
    //     return dp[n]=solver(n-1,dp)+solver(n-2,dp);
    // }
    int fib(int n) {
        if(n<=0)    return n;
        vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
        // return solver(n,dp);
        // if(n==0)    return 0;
        // if(n==1)    return 1;
        // return(fib(n-1)+fib(n-2));
    }
};