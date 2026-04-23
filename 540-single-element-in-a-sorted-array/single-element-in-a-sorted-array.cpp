class Solution {
public:
    // Alternate optimal solution idea :- Use binary search where you compare nums[mid] with nums[mid ^ 1], and if they’re equal move right, otherwise move left.
    int singleNonDuplicate(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])    return nums[mid];
            if(nums[mid-1]==nums[mid]){
                if((mid+1)%2){
                    right=mid+1;   
                }
                else{
                    left=mid+1;
                }
            }
            else{
                if((mid)%2){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
        }
        return nums[left];
    }
};