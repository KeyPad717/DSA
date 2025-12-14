class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int maxi=0,mini=0,n=nums.size();
        //while(k--){
            for(int i=0;i<k;i++){
                maxi+=nums[i];
                mini+=nums[n-1-i];
            }
        
        return(abs(maxi-mini));
    }
};