class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int left=0, right=n-1, missing;
        while(left<=right){
            int mid=left+(right-left)/2;
            missing=arr[mid]-(mid+1);
            if(missing<k){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return right+1+k;
    }
};