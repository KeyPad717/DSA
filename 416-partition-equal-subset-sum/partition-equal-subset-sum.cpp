class Solution {
public:
    bool helper(int idx, vector<int>& nums, vector<vector<int>>& dp, int sum){
        if(sum==0)  return true;
        if(idx<0 || sum<0)  return false;
        if(dp[idx][sum]!=-1)  return dp[idx][sum]==1;
        bool pick=false;
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
        int n=nums.size(), targetSum=(sum/2);
        vector<vector<bool>> dp(n, vector<bool> (targetSum+1));
        for(int s=0;s<=targetSum;s++){
            if(nums[0]==s)   dp[0][s]=true;
            else            dp[0][s]=false;
        }
        for(int idx=0;idx<n;idx++){
            dp[idx][0]=true;
        }
        for(int idx=1;idx<n;idx++){
            for(int s=1;s<=targetSum;s++){
                bool pick=false;
                if(nums[idx]<=s){
                    pick=dp[idx-1][s-nums[idx]];
                    //helper(idx-1, nums, dp, sum-nums[idx]);
                }
                dp[idx][s]=(pick || dp[idx-1][s]);
                //helper(idx-1, nums, dp, sum));
            }
        }
        return dp[n-1][targetSum];
    }
};