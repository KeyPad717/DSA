class Solution {
public:
    void helper(vector<int>& nums, int n, int idx, vector<int>& v, vector<vector<int>>& v1){
        if(idx==n){
            for(int i=0;i<v1.size();i++){
                if(v==v1[i])    return ;
            }
            v1.push_back(v);
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
        vector<vector<int>> v1;
        helper(nums, n, 0, v, v1);
        return v1;
    }
};