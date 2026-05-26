class Solution {
public:
    void helper(vector<int>& nums, int n, int idx, vector<int>& v, set<vector<int>>& v1){
        if(idx==n){
            v1.insert(v);
            return ;
        }
        helper(nums, n, idx+1, v, v1);
        v.push_back(nums[idx]);
        helper(nums, n, idx+1, v, v1);
        v.pop_back();
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<int> v;
        set<vector<int>> v1;
        helper(nums, n, 0, v, v1);
        vector<vector<int>> v2(v1.begin(), v1.end());
        return v2;
    }
};