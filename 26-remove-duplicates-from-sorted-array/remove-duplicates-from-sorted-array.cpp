class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(), i=0, j=1;
        while(i<n && j<n){
            if(nums[i]==nums[j]){
                j++;
            }
            else{
                nums[i+1]=nums[j];
                i=i+1;
            }
        }
        return i+1;
    }
};