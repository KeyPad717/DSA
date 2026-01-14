class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int maj=nums[0];
        for(int i=1;i<nums.size();i++){
            if(count==0)    maj=nums[i];
            if(nums[i]==maj)    count++;
            else    count--;
        }
        // int c=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==maj)    c++;
        // }
        return(maj);
    }
};