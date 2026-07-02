class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum=1LL * (nums.size()*(nums.size()+1))/2;
        int sum1=accumulate(nums.begin(), nums.end(), 0);
        return abs(sum-sum1);
    }
};