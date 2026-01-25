class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n=nums.size(), idx=-1;
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1])   idx=i;
        }
        if(idx==-1)   return 0;
        return idx;
    }
};