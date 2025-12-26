class Solution {
public:
    // int solver(int n, vector<int> &dp){
    //     if(n==1)    return 1;
    //     if(n==2)    return 2;
    //     if(dp[n]!=-1)   return dp[n];
    //     dp[n]=solver(n-1,dp)+solver(n-2,dp);
    //     return(dp[n]);
    // }
    int climbStairs(int n) {
        if(n==1)    return 1;
        if(n==2)    return 2;
        int prev=1;
        int curr=2;
        int next;
        for(int i=3;i<n+1;i++){
            next=curr+prev;
            prev=curr;
            curr=next;
        }
        return(next);
    }
};