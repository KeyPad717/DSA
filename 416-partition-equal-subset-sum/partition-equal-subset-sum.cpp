class Solution {
public:
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
        }
        for(int idx=0;idx<n;idx++){
            dp[idx][0]=true;
        }
        for(int idx=1;idx<n;idx++){
            for(int s=1;s<=targetSum;s++){
                bool pick=false;
                if(nums[idx]<=s){
                    pick=dp[idx-1][s-nums[idx]];
                }
                dp[idx][s]=(pick || dp[idx-1][s]);
            }
        }
        return dp[n-1][targetSum];
    }
};