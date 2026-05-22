class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(), nums.end(), 0), n=nums.size();
        int mini=*min_element(nums.begin(), nums.end()), maxi=*max_element(nums.begin(), nums.end());
        if(k==1)    return sum;
        if(k==n)    return maxi;
        int left=maxi, right=sum;
        while(left<=right){
            int mid=left+(right-left)/2, subarr=1, curSum=nums[0];
            for(int i=1;i<n;i++){
                if(curSum+nums[i]<=mid){
                    curSum+=nums[i];
                }
                else{
                    curSum=nums[i];
                    subarr++;
                }
            }
            if(subarr>k){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return left;
    }
};