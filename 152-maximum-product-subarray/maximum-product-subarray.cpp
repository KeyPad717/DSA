class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(), prod=1, maxi=INT_MIN, f=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                maxi=max(maxi,0);
                prod=1;
            }  
            else{
                prod*=nums[i];
                maxi=max(maxi,prod);
            }
        }
        prod=1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==0){
                maxi=max(maxi,0);
                prod=1;
            }  
            else{
                prod*=nums[i];
                maxi=max(maxi,prod);
            }
        }
        return maxi;
    }
};