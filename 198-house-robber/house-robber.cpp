class Solution {
public:
    // int helper(int idx, vector<int>& nums, int maxi, vector<int>& dp){
    //     if(idx==0){
    //         //dp[0]=nums[0];
    //         return nums[0];
    //     }  
    //     if(idx<0)   return 0;
    //     if(dp[idx]==-1){
    //         int pick=nums[idx]+helper(idx-2, nums, INT_MIN, dp);
    //         int not_pick=helper(idx-1, nums, INT_MIN, dp);
    //         dp[idx]=max(pick,not_pick);
    //         return(dp[idx]);
    //     }
    //     return dp[idx];
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        //vector<int> dp(n,-1);
        if(n==1)    return nums[0];
        if(n==2)    return(max(nums[0],nums[1]));
        int prev=nums[0], val;
        int curr=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int pick=nums[i]+prev;
            int not_pick=curr;
            val=max(pick,not_pick);
            prev=curr;
            curr=val;
        }
        return(val);
    }
};