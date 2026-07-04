class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx=-1, n=nums.size(), mini=INT_MAX, idx2;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                idx=i-1;
                break;
            }
        }
        if(idx==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(int i=idx+1;i<n;i++){
                if(nums[i]>nums[idx]){
                    if(mini>=nums[i]){
                        idx2=i;
                        mini=nums[i];
                    }
                }
            }
            swap(nums[idx2],nums[idx]);
            reverse(nums.begin()+idx+1, nums.end());
        }
    }
};