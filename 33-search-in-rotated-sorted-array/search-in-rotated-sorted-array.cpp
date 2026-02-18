class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(),j,i,f=0;
        if(n==1){
            if(target != nums[0])   return(-1);
        }
        if(n==2){
            if(nums[0]==target) return(0);
            else if(nums[1]==target) return(1);
            else    return(-1);
        }
        int low=0,high=n-1,mid;
        while(high>=low){
            mid=low+(high-low)/2;
            if(nums[mid]==target)   return mid;
            else if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<=nums[mid])  high=mid-1;
                else                                        low=mid+1;
            }
            else{
                if(nums[high]>=target && target>=nums[mid]) low=mid+1;
                else                                        high=mid-1;
            }
            // else if(nums[mid]>target)       high=mid-1;
            // else if(nums[mid]<target)       low=mid+1;
        }
        return(-1);
    }
};