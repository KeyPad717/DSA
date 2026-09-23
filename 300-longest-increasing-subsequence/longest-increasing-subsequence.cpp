class Solution {
public:
    int helper(int prev_idx, int idx, vector<int>& nums, vector<vector<int>>& dp){
        if(idx>=nums.size())    return 0;
        if(prev_idx!=-1 && dp[prev_idx][idx]!=-1)   return dp[prev_idx][idx];
        int take=0;
        if(prev_idx==-1 || nums[idx]>nums[prev_idx]){
            take=1+helper(idx, idx+1, nums,dp);
        }
        int not_take=helper(prev_idx, idx+1, nums,dp);
        if(prev_idx!=-1)    dp[prev_idx][idx]=max(take, not_take);
        return max(take, not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int> (nums.size(),-1));
        return helper(-1, 0, nums, dp);
    }
};