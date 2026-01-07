class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //better approach as there's no auxiliary space
        int n=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                nums.erase(nums.begin()+i);
                n++;
                i--;
            }
        }
        while(n!=0){
            nums.push_back(0);
            n--;
        }
    }
};