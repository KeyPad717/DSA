class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)    return 0;
        if(n==2){
            if(nums[0]>nums[1]) return 0;
            else                return 1;
        }
        int left=0, right=n-1;
        while(left<right){
            int mid=left+(right-left)/2;
            cout<<mid<<" "<<nums[mid]<<endl;
            if(mid==0 || mid==n-1){
                return mid;
            }
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                return mid;
            }
            else if (nums[mid]>nums[mid+1]){
                right=mid;
            }
            else {
                left=mid+1;
            }
        }
        return left;
    }
};