class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size(),f=0;
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n])   f++;
            if(f>1) break;
        }
        if(f>1) return false;
        return true;
    }
};