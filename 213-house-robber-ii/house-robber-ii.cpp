class Solution {
public:
    // int helper(int stopIdx, int idx, const vector<int>& nums, vector<int> &dp){
    //     if(idx==stopIdx)    return nums[idx];
    //     if(idx<stopIdx)     return 0;
    //     if(dp[idx]!=-1)     return dp[idx];
    //     int pick=nums[idx]+helper(stopIdx,idx-2,nums,dp);
    //     int not_pick=helper(stopIdx,idx-1,nums,dp);
    //     return dp[idx]=max(pick,not_pick);
    // }
    int tabHelper(int start, int end, vector<int>& nums){
        vector<int> dp(nums.size());
        dp[start]=nums[start];
        for(int i=start+1;i<=end;i++){
            int pick=nums[i];
            if(i-2>=start)   pick+=dp[i-2];
            int not_pick=dp[i-1];
            dp[i]=max(pick,not_pick);
        }
        return dp[end];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)  return max(0,nums[0]);
        int n=nums.size();
        return max(tabHelper(0,n-2,nums),tabHelper(1,n-1,nums));
    }
};