class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN, sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<0){
                maxi=max(maxi,sum);
                sum=0;
            }
            else{
                maxi=max(maxi,sum);
            }
        }
        return maxi;
    }
};