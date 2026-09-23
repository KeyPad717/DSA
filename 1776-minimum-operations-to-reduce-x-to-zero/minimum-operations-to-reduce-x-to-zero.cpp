class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int i=0,n=nums.size(), sum=0;
        int j=0, maxi=-1;
        for(int y:nums) sum+=y;
        int target=sum-x;
        if(target==0)   return n;
        if(target<0)    return -1;
        int len=0, curSum=0;
        for(int p=0;p<n;p++){
            curSum+=nums[p];
            while(curSum>target){
                curSum-=nums[j];
                j++;
            }
            if(curSum==target)  maxi=max(maxi, p-j+1);
        }
        if(maxi==-1) return -1;
        return n-maxi;
    }
};