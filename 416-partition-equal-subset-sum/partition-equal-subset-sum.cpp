class Solution {
public:
    bool helper(int idx, vector<int>& nums, vector<vector<int>>& dp, int sum){
        if(sum==0)  return true;
        if(idx<0 || sum<0)  return false;
        if(dp[idx][sum]!=-1)  return dp[idx][sum]==1;
        int pick=false;
        if(nums[idx]<=sum){
            pick=helper(idx-1, nums, dp, sum-nums[idx]);
        }
        dp[idx][sum]=(pick || helper(idx-1, nums, dp, sum));
        return dp[idx][sum]==1;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int x:nums){
            sum+=x;
        }
        if(sum&1)   return false;
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int> ((sum/2)+1,-1));
        return helper(n-1, nums, dp, sum/2);
    }
};