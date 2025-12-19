class Solution {
public:
    bool solve(int n, int k, vector<int>& nums, vector<vector<int>>& dp){
        if(k==0)    return true;
        if(n==0)    return false;
        if(dp[n][k]!=-1)    return dp[n][k];
        if(nums[n-1]<=k){
            dp[n][k]=solve(n-1,k-nums[n-1],nums,dp)||solve(n-1,k,nums,dp);
            return dp[n][k];
        }
        dp[n][k]=solve(n-1,k,nums,dp);
        return dp[n][k];
    }
    bool canPartition(vector<int>& nums) {
        int x=accumulate(nums.begin(),nums.end(),0);
        if(x%2!=0)  return false;
        int n=nums.size(),k=x/2;
        vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
        return(solve(n,k,nums,dp));
    }
};