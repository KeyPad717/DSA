class Solution {
public:
    int helper(int idx, int prev_idx, vector<int>& nums, vector<vector<int>>& dp){
        if(idx==nums.size())  return 0;
        if(prev_idx != -1 && dp[prev_idx][idx]!=-1) return dp[prev_idx][idx];
        int take=0;
        if(prev_idx==-1 || nums[idx]>nums[prev_idx]){
            take=1+helper(idx+1, idx, nums, dp);
        }
        int not_take=helper(idx+1, prev_idx, nums, dp);
        if(prev_idx != -1) return dp[prev_idx][idx]=max(take, not_take);
        return max(take, not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int> (nums.size(), -1));//{prev_idx, idx}
        return helper(0, -1, nums, dp);
    }
};