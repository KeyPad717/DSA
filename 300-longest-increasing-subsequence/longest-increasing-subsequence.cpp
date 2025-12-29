class Solution {
public:
    int solver(int idx, vector<int>& nums, int n, int prev_idx,vector<vector<int>> &dp){
        if(idx==n) return 0;
        if(dp[idx][prev_idx+1]!=-1) return dp[idx][prev_idx+1];
        dp[idx][prev_idx+1]=solver(idx+1,nums,n,prev_idx,dp);
        if(prev_idx==-1||nums[idx]>nums[prev_idx]){
            dp[idx][prev_idx+1] = max(dp[idx][prev_idx+1], 1+(solver(idx+1,nums,n,idx,dp)));
        }
        return dp[idx][prev_idx+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return solver(0,nums,n,-1,dp);
    }
};