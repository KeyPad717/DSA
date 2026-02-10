class Solution {
public:
    int solver(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int n=nums.size(),i=0,j=0,sum=0,count=0;
        while(i<n && j<n){
            sum+=nums[j];
            while(sum>goal){
                sum-=nums[i];
                i++;
            }
            count+=j-i+1;
            j++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solver(nums,goal)-solver(nums,goal-1);
    }
};