class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)    return nums[0];
        int prev=nums[0];
        int curr=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int pick=nums[i]+prev;
            int not_pick=curr;
            prev=curr;
            curr=max(pick,not_pick);
        }
        return curr;
    }
};