class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int i=0, j=nums.size()-1, posi=nums.size()-1;
        while(i<=j){
            if(abs(nums[i])>=abs(nums[j])){
                ans[posi]=nums[i]*nums[i];
                posi--;
                i++;
            } 
            else{
                ans[posi]=nums[j]*nums[j];
                posi--;
                j--;
            }                    
        }
        return ans;
    }
};