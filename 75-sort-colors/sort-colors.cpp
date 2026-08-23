class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0, mid=0, high=nums.size()-1;
        while(low<=high && mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{//nums[mid]==2
                swap(nums[mid],nums[high]);
                high--;
                //no mid++ as current nums[high] could be 0
            }
        }
    }
};