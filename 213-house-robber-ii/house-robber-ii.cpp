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
        //vector<int> dp(nums.size());
        int prev=nums[start];
        int curr=max(prev,nums[start+1]);
        for(int i=start+2;i<=end;i++){
            int pick=nums[i];
            pick+=prev;
            int not_pick=curr;
            prev=curr;
            curr=max(pick,not_pick);
        }
        return curr;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)  return nums[0];
        if(nums.size()==2)  return max(nums[0],nums[1]);
        int n=nums.size();
        return max(tabHelper(0,n-2,nums),tabHelper(1,n-1,nums));
    }
};