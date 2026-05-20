class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int maxi=*max_element(arr.begin(),arr.end());
        int left=1, right=maxi+k, n=arr.size();
        while(left<=right){
            int mid=left+(right-left)/2, count=0;
            for(int i=0;i<n;i++){
                if(arr[i]<=mid){
                    count++;
                }
            }
            if(count==mid)  left=mid+1;
            else if(count<mid){
                if(abs(count-mid)<k)    left=mid+1;
                //else if (abs(count-mid)==k)   return mid;
                else                    right=mid-1;             
            }
        }
        return left;
    }
};