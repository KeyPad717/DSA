class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size(), len=1;
        for(int i=0;i<2*n-1;i++){
            if(len==n)  return true;
            if(nums[i%n]>nums[((i+1)%n)]){
                len=1;
                continue;
            }
            len++;
        }
        return false;
    }
};