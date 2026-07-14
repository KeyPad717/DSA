class Solution {
public:
    void mergeSort(int left,int mid, int right, vector<int> &nums, int& cnt){
        vector<int> temp;
        temp.reserve(right-left+1);
        int a=left, b=mid+1;
        int c=mid+1;
        int prev=0;
        for(int i=a;i<=mid;i++){
            long long x=1LL * nums[i];
            long long y=1LL;
            while(c<=right && (1LL * nums[i])>(2LL * nums[c]))    c++;
            cnt+=c-(mid+1);
        }
        while(a<=mid && b<=right){
            if(nums[a]>nums[b]){
                temp.push_back(nums[b++]);
            }
            else{
                temp.push_back(nums[a++]);
            }
        }
        while(a<=mid){
            temp.push_back(nums[a++]);
        }
        while(b<=right){
            temp.push_back(nums[b++]);
        }
        for(int i=left;i<=right;i++){
            nums[i]=temp[i-left];
        }
    }
    void merge(int left, int right, vector<int> &nums, int& cnt){
        if(left>=right) return;
        int mid=left+(right-left)/2;
        merge(left,mid,nums,cnt);
        merge(mid+1,right,nums,cnt);
        mergeSort(left,mid,right,nums,cnt);
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size(), cnt=0;
        merge(0,n-1,nums,cnt);
        return cnt;
    }
};