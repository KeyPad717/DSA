class Solution {
public:
    int helper(int idx, vector<int>& nums, int sum, vector<vector<int>>& dp){
        if(idx==nums.size()){
            if(sum==0)  return 0;
            else        return 10000;
        }
        int val=nums[idx], mini=INT_MAX, op=0;
        if(dp[idx][sum]!=INT_MAX)   return dp[idx][sum];
        if(val<=sum){
            int take=helper(idx+1, nums, sum-val,dp);
            if(take!=INT_MAX)    mini=min(mini,take);
        }
        while(val>0){
            op++;
            val/=2;
            if(val<=sum){
                int take=helper(idx+1, nums, sum-val, dp);
                if(take!=INT_MAX)    mini=min(mini, op+take);
            }
        }
        op=0;
        val=nums[idx];
        while(val<=sum){
            op++;
            val*=2;
            if(val<=sum){
                int take=helper(idx+1, nums, sum-val, dp);
                if(take!=INT_MAX)    mini=min(mini, op+take);
            }
        }
        int not_take=helper(idx+1, nums, sum,dp);
        mini=min(mini,not_take);
        return dp[idx][sum]=mini;
    }
    int minOperations(vector<int>& nums, int sum) {
        vector<vector<int>> dp(nums.size(), vector<int> (2*sum,INT_MAX));
        int val=helper(0,nums,sum,dp);
        if(val==10000)    return -1;
        return val;
    }
};