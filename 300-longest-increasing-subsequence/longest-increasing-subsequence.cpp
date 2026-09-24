class Solution {
public:
    // int helper(int prev_idx, int idx, vector<int>& nums, vector<vector<int>>& dp){
    //     if(idx>=nums.size())    return 0;
    //     if(prev_idx!=-1 && dp[prev_idx][idx]!=-1)   return dp[prev_idx][idx];
    //     int take=0;
    //     if(prev_idx==-1 || nums[idx]>nums[prev_idx]){
    //         take=1+helper(idx, idx+1, nums,dp);
    //     }
    //     int not_take=helper(prev_idx, idx+1, nums,dp);
    //     if(prev_idx!=-1)    dp[prev_idx][idx]=max(take, not_take);
    //     return max(take, not_take);
    // }
    int lengthOfLIS(vector<int>& nums){
        int n=nums.size();
        vector<int> res;
        res.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>res.back())  res.push_back(nums[i]);
            else{
                int idx=lower_bound(res.begin(), res.end(), nums[i])-res.begin();
                res[idx]=nums[i];
            }
        }
        return res.size();
    }
};