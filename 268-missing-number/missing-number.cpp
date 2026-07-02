class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int x1=0;
        for(int i=1;i<=n;i++){
            x1=x1^i;
        }
        for(int i=0;i<n;i++){
            x1=x1^nums[i];
        }
        return x1;
    }
};