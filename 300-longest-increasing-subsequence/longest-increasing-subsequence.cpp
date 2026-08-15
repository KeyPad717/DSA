class Solution {
public:
    int helper(int idx, vector<int>& nums, int prevIdx, vector<vector<int>>& dp){
        if(idx==nums.size()){
            return 0;
        }
        if(dp[idx][prevIdx]!=-1)    return dp[idx][prevIdx];
        int take=0;
        if(prevIdx==nums.size()){
            take=1+helper(idx+1,nums,idx,dp);
        }
        else if(nums[idx]>nums[prevIdx]){
            take=1+helper(idx+1,nums,idx,dp);
        }
        return dp[idx][prevIdx]=max(take,helper(idx+1,nums,prevIdx,dp));
    }
    int lengthOfLIS(vector<int>& nums) { 
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1));
        for(int pidx=0;pidx<=n;pidx++){
            dp[n][pidx]=0;
        }
        for(int idx=n-1;idx>=0;idx--){
            for(int pidx=0;pidx<=n;pidx++){
                int take=0;
                if(pidx==n || nums[idx]>nums[pidx]){
                    take=1+dp[idx+1][idx];
                }
                dp[idx][pidx]=max(take, dp[idx+1][pidx]);
            }
        }
        return dp[0][n];
    }
};