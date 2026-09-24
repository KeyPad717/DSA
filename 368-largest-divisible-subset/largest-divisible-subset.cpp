class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //if(nums.size()==1)  return nums;
        int maxi=1;
        sort(nums.begin(), nums.end());
        int n=nums.size(), last_idx=0;
        vector<int> res;
        vector<int> idx(n), dp(n,1);
        for(int i=0;i<n;i++){
            idx[i]=i;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if((nums[i]%nums[j])==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    idx[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                last_idx=i;
            }
        }
        res.push_back(nums[last_idx]);
        while(idx[last_idx]!=last_idx){
            last_idx=idx[last_idx];
            res.push_back(nums[last_idx]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};