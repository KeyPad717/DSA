class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int mid=n/2,low=0,high=n-1;
        if(nums[mid]==target)   return(mid);
        while(nums[mid]!=target && high!=low){
            if(nums[mid]==target)   return(mid);
            if(target>nums[mid]){
                low=mid+1;
                mid=(low+high)/2;
                cout<<nums[mid]<<endl;
                continue;
            }
            else if(target<nums[mid]){
                high=mid;
                mid=(low+high)/2;
                continue;
            }
        }
        if(nums[mid]==target)   return(mid);
        else    return -1;
    }
};