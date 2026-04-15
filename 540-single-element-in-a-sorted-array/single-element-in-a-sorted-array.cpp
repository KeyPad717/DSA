class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            cout<<mid<<" "<<nums[mid]<<" "<<endl;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])    return nums[mid];
            if(nums[mid-1]==nums[mid]){
                if((mid+1)%2==0){
                    left=mid+1;
                    cout<<"a"<<endl;
                }
                else{
                    right=mid+1;
                    cout<<"b"<<endl;
                }
            }
            else{
                if((mid)%2==0){
                    left=mid+1;
                    cout<<"c"<<endl;
                }
                else{
                    right=mid-1;
                    cout<<"d"<<endl;
                }
            }
        }
        return nums[left];
    }
};