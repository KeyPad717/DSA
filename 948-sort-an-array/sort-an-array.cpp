class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high, vector<int>& temp){
        int left=low, right=mid+1, k=low;
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp[k++]=nums[left++];
            }
            else{
                temp[k++]=nums[right++];
            }
        }
        while(left<=mid){
            temp[k++]=nums[left++];
        }
        while(right<=high){
            temp[k++]=nums[right++];
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i];
        }
    }
    void mergeSort(vector<int>& nums, int low, int high, vector<int>& temp){
        if(low>=high)   return;
        int mid=low+(high-low)/2;
        mergeSort(nums, low, mid, temp);
        mergeSort(nums, mid+1, high, temp);
        merge(nums, low, mid, high, temp);
    }
    vector<int> sortArray(vector<int>& nums) {
        if(nums.empty())    return nums;
        vector<int> temp(nums.size());
        mergeSort(nums, 0, nums.size()-1, temp);
        return nums;
    }
};