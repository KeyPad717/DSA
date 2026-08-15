class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int x:nums){
            sum+=x;
        }
        if(sum&1)   return false;
        int n=nums.size(), targetSum=(sum/2);
        vector<bool> prev(targetSum+1), curr(targetSum+1);
        //vector<vector<bool>> dp(n, vector<bool> (targetSum+1));
        for(int s=0;s<=targetSum;s++){
            if(nums[0]==s)   prev[s]=true;
        }
        for(int idx=1;idx<n;idx++){
            for(int s=1;s<=targetSum;s++){
                curr[0]=true;
                bool pick=false;
                if(nums[idx]<=s){
                    pick=prev[s-nums[idx]];
                }
                curr[s]=(pick || prev[s]);
            }
            prev=curr;
        }
        return prev[targetSum];
    }
};