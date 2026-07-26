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
        int n=nums.size();
        vector<int> dp1(nums.size(),-1),dp2(nums.size(),-1);
        dp1[0]=nums[0];
        for(int i=1;i<n-1;i++){
            int pick=0;
            if(i>1) pick=nums[i]+dp1[i-2];
            int not_pick=dp1[i-1];
            dp1[i]=max(pick,not_pick);
        }
        dp2[1]=nums[1];
        for(int i=2;i<n;i++){
            int pick=0;
            if(i==2) pick=nums[i];
            else     pick=nums[i]+dp2[i-2];
            int not_pick=dp2[i-1];
            dp2[i]=max(pick,not_pick);
        }
        return max(dp1[n-2],dp2[n-1]);
    }
};