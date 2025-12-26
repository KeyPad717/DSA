class Solution {
public:
    int solver(int n, vector<int>& nums,vector<int> &dp){
        if(n==0)    return 0;
        if(n==1)    return nums[n-1];
        int take=0,nottake=0;
        if(dp[n]!=-1)   return dp[n];
        take=nums[n-1]+solver(n-2,nums,dp);
        nottake=solver(n-1,nums,dp);
        return(dp[n]=max(take,nottake));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return(solver(n,nums,dp));
    }
};