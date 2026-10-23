class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        int k=INT_MAX;
        bool swap=false;
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                k&=(nums[i]);
                swap=true;
            }
        }
        if(swap)    return k;
        return 0;
    }
};