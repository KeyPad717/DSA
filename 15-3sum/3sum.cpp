class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])   continue;
            int j=i+1, k=n-1;
            while(j<n && j<k){  
                if(nums[j]+nums[k]+nums[i]==0){
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j-1]==nums[j]) j++;
                    while(j<k && nums[k+1]==nums[k]) k--;
                }
                else if(nums[j]+nums[k]+nums[i]<0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return res;
    }
};