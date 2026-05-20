class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1, right=*max_element(nums.begin(), nums.end()), n=nums.size();
        while(left<=right){
            int mid=left+(right-left)/2, sum=0;
            for(int i=0;i<n;i++){
                if(nums[i]%mid==0)      sum+=nums[i]/mid;
                else if(nums[i]<mid)    sum+=1;
                else                    sum+=nums[i]/mid+1;
            }
            if(sum>threshold){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return left;
    }
};