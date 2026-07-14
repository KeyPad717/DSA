class Solution {
public:
    void mergeSort(int left, int mid , int right, vector<int>& nums, vector<int>& sorted){
        int eleP=left;
        int a=left, b=mid+1;
        while(eleP<=right && a<=mid && b<=right){
            if(nums[a]<=nums[b]){
                sorted[eleP]=nums[a];
                a++;
                eleP++;
            }
            else{
                sorted[eleP]=nums[b];
                b++; 
                eleP++;
            }
        }
        while(eleP<=right && a<=mid){
            sorted[eleP]=nums[a];
            eleP++;
            a++;
        }
        while(eleP<=right && b<=right){
            sorted[eleP]=nums[b];
            eleP++;
            b++; 
        }
        for(int i=left;i<=right;i++){
            nums[i]=sorted[i];
        }
    }
    void merge(int left, int right, vector<int>& nums, vector<int>& sorted){
        if(left>=right) return;
        int mid=left+(right-left)/2;
        merge(left,mid,nums, sorted);
        merge(mid+1, right, nums, sorted);
        mergeSort(left, mid, right, nums, sorted);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> sorted(nums.size());
        merge(0,n-1,nums, sorted);
        return nums;
    }
};