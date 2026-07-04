class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int x=INT_MIN, idx=-1, sum=0, n=nums.size(), i=0;
        int left=nums[0], right=nums[k];
        for(int j=k;j<n;j++){
            int temp=nums[j]+left;
            sum=max(sum,temp);
            i++;
            left=max(nums[i],left);
        }
        return sum;
    }
};