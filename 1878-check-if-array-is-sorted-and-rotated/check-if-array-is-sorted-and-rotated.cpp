class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size(), len=1;
        if(n==1)    return true;
        for(int i=0;i<2*n-1;i++){
            if(nums[i%n]>nums[((i+1)%n)])  len=1;
            else    len++;
            if(len==n)  return true;
        }
        return false;
    }
};