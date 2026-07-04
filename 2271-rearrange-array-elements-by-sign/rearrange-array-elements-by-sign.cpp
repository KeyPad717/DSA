class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> even;
        vector<int> odd;
        vector<int> res;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0)  odd.push_back(nums[i]);
            else            even.push_back(nums[i]);
        }
        for(int i=0;i<(nums.size())/2;i++){
            res.push_back(even[i]);
            res.push_back(odd[i]);
        }
        return res;
    }   
};