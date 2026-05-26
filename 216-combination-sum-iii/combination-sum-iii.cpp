class Solution {
public:
    void helper(int len, int idx, int k, int n, vector<vector<int>>& ans, vector<int>& v, vector<int> nums){
        if(n==0 && v.size()==k){
            ans.push_back(v);
            return ;
        }
        if(idx>=len) return ;
        //cout<<idx<<" "<<nums[idx]<<" "<<n<<endl;
        if( nums[idx]<=n){
            v.push_back(nums[idx]);
            helper(len, idx+1, k, n-nums[idx], ans, v, nums);
            v.pop_back();
        }
        helper(len, idx+1, k, n, ans, v, nums);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> nums{1,2,3,4,5,6,7,8,9};
        vector<int> v;
        helper(9, 0, k, n, ans, v, nums);
        return ans;
    }
};