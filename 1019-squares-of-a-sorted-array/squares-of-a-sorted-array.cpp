class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]*nums[i];
        }
        int mini=nums[0], idx=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<mini){
                idx=i;
                mini=nums[i];
            }
        }
        if(idx==0)  return nums;
        int i=idx-1, j=idx+1;
        ans.push_back(nums[idx]);
        while(i>=0 && j<nums.size()){
            if(nums[i]<=nums[j]){
                ans.push_back(nums[i]);
                i--;
            } 
            else{
                ans.push_back(nums[j]);
                j++;
            }                    
        }
        while(i>=0){
            ans.push_back(nums[i]);
            i--;
        }
        while(j<nums.size()){
            ans.push_back(nums[j]);
            j++;
        }
        return ans;
    }
};