class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(),i=0;
        while(n--){
            if(nums[i]==0){
                nums.push_back(0);
                nums.erase(nums.begin()+i); 
                i--;
            }
            i++;
        }
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0){
        //         nums.push_back(0);
        //         nums.erase(nums.begin()+i);
                
        //     }
        // }
    }
};