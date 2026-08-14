class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int maxi=nums[0], idx=0;
        int i=0, j=nums.size()-1;
        while(i<=j){
            if(abs(nums[i])>=abs(nums[j])){
                ans.push_back(nums[i]);
                i++;
            } 
            else{
                ans.push_back(nums[j]);
                j--;
            }                    
        }
        reverse(ans.begin(), ans.end());
        for(int i=0;i<ans.size();i++){
            ans[i]=ans[i]*ans[i];
        }
        return ans;
    }
};