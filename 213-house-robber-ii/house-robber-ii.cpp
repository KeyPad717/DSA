class Solution {
public:
    int solver(int n, vector<int>& nums,vector<int> &dp){
        if(n==0)    return 0;
        if(n==1)    return nums[n-1];
        int take=0,nottake=0;
        if(dp[n]!=-1)   return dp[n];
        take=nums[n-1]+solver(n-2,nums,dp);
        nottake=solver(n-1,nums,dp);
        return(dp[n]=max(take,nottake));
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)    return nums[0];
        int n=nums.size()-1;
        int x=nums[n];
        nums.pop_back();
        vector<int> dp1(n+1,-1),dp2(n+1,-1);
        int a=solver(n,nums,dp1);
        nums.push_back(x);
        nums.erase(nums.begin());
        int b=solver(n,nums,dp2);
        return(max(a,b));
    }
};