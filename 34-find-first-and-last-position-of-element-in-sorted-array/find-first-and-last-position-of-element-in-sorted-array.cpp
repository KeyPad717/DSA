class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low1=0, low2=0, high1=nums.size()-1, high2=nums.size()-1, idx1=-1, idx2=-1;
        while(low1<=high1){
            int mid=low1+(high1-low1)/2;
            cout<<"a: "<<low1<<" "<<high1<<" "<<mid<<" "<<nums[mid]<<endl;
            if(nums[mid]==target){
                high1=mid-1;
                idx1=mid;
            }
            else if(nums[mid]<target){
                low1=mid+1;
            }
            else{
                high1=mid-1;
            }
        }
        while(low2<=high2){
            int mid=low2+(high2-low2)/2;
            cout<<"b: "<<low2<<" "<<high2<<" "<<mid<<endl;
            if(nums[mid]==target){
                low2=mid+1;
                idx2=mid;
            }
            else if(nums[mid]<target){
                low2=mid+1;
            }
            else{
                high2=mid-1;
            }
        }
        return {idx1,idx2};
    }
};