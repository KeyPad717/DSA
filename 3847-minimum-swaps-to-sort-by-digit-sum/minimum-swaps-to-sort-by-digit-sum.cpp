class Solution {
public:
    int getDigitSum(int num){
        int digitSum=0;
        while(num>0){
            digitSum+=(num%10);
            num/=10;
        }
        return digitSum;
    }
    int minSwaps(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        int swaps=0;
        vector<int> nums1{nums.begin(), nums.end()};
        auto lambda=[&](int num1, int num2){
            int digitSum1=getDigitSum(num1);
            int digitSum2=getDigitSum(num2);
            if(digitSum1!=digitSum2){
                return digitSum1<digitSum2;
            }
            else{
                return num1<num2;
            }
        };
        sort(nums1.begin(), nums1.end(), lambda);
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=nums1[i]){
                int idx=mp[nums1[i]];
                swap(nums[i],nums[idx]);
                mp[nums[i]]=i;
                mp[nums[idx]]=idx;
                swaps++;
            }
        }
        return swaps;
    }
};