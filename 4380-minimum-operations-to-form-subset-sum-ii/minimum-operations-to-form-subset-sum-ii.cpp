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
            if(take!=10000)    mini=min(mini,take);
        }
        while(val>0){
            op++;
            val/=2;
            int val1=val, op1=0;
            if(val1==0) break;
            while(val1<=sum){
                op1++;
                val1*=2;
                if(val1<=sum){
                    int take1=helper(idx+1, nums, sum-val1, dp);
                    if(take1!=10000)    mini=min(mini, op1+op+take1);
                }
            }
            if(val<=sum){
                int take=helper(idx+1, nums, sum-val, dp);
                if(take!=10000)    mini=min(mini, op+take);
            }
        }
        val=nums[idx];
        op=0;
        while(val<=sum){
            op++;
            val*=2;
            if(val<=sum){
                int take=helper(idx+1, nums, sum-val, dp);
                if(take!=10000)    mini=min(mini, op+take);
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