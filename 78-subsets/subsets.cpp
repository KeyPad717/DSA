class Solution {
public:
    void helper(int idx, int n, vector<vector<int>>& v1, vector<int>& v, vector<int>& nums){
        if(idx==n){
            v1.push_back(v);
            return ;
        }
        helper(idx+1, n, v1, v, nums);
        v.push_back(nums[idx]);
        helper(idx+1, n, v1, v, nums);
        v.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v1;
        vector<int> v;
        int n=nums.size();
        helper(0, n, v1, v, nums);
        return v1;
    }
};