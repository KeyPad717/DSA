class Solution {
public:
    int helper(int stopIdx, int idx, const vector<int>& nums, vector<int> &dp){
        if(idx==stopIdx)    return nums[idx];
        if(idx<stopIdx)     return 0;
        if(dp[idx]!=-1)     return dp[idx];
        int pick=nums[idx]+helper(stopIdx,idx-2,nums,dp);
        int not_pick=helper(stopIdx,idx-1,nums,dp);
        return dp[idx]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)  return max(0,nums[0]);
        vector<int> dp1(nums.size(),-1),dp2(nums.size(),-1);
        return max( helper(0,nums.size()-2,nums,dp1) , helper(1,nums.size()-1,nums,dp2));
    }
};