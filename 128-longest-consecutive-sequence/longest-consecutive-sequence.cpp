class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())    return 0;
        sort(nums.begin(), nums.end());
        int len=1, maxi=INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1])  continue;
            if(nums[i]+1==nums[i+1]){
                len++;
            }
            else{
                maxi=max(maxi,len);
                len=1;
            }
        }
        maxi=max(maxi,len);
        return maxi;
    }
};