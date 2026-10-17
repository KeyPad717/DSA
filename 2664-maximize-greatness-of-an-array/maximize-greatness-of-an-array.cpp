class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0, j=0, ans=0;
        while(i<nums.size() && j<nums.size()){
            if(nums[i]>=nums[j])    j++;
            else{
                ans++;
                i++;
                j++;
            }
        }
        return ans;
    }
};