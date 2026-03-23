class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size(), idx=-1, count=0, temp;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                idx=i+1;
                break;
            }
        }
        if(idx==-1) return true;
        for(int i=idx;i<n-1;i++){
            if(nums[i]<=nums[i+1])   count++;
        }
        if(nums[0]>=nums[n-1])   count++;
        for(int i=0;i<idx-1;i++){
            if(nums[i]<=nums[i+1])   count++;
        }
        if(count==n-1)  return true;
        return false;
    }
};