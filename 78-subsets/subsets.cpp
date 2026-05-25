class Solution {
public:
    void solve(int index, int n, vector<int>& res, vector<vector<int>>& ans,
               vector<int>& nums) {

        if (index == n) {
            ans.push_back(res);
            return;
        }

        res.push_back(nums[index]);
        solve(index + 1, n, res, ans, nums);
        res.pop_back();
        solve(index + 1, n, res, ans, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        int n = nums.size();
        solve(0, n, res, ans, nums);

        return ans;
    }
};