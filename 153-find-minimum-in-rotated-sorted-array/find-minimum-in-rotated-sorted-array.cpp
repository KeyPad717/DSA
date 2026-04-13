class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0, right=nums.size()-1, mini=INT_MAX;
        while(left<=right){
            int mid= left + (right - left)/2;
            if(nums[mid] > nums[right]){
                left=mid+1;
                mini=min(mini,nums[mid]);
            }
            else{
                right=mid-1;
                mini=min(mini,nums[mid]);
            }
        }
        return mini;
    }
};