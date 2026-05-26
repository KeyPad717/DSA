class Solution {
public:
    void helper(vector<int>& candidates, int target, int idx, int n, vector<vector<int>>& v1, vector<int>& v){
        if(target==0){
            
            v1.push_back(v);
            return ;
        }
        if(idx==n){
            return ;
        }
        if(candidates[idx]<=target) {
            v.push_back(candidates[idx]);
            helper(candidates, target-candidates[idx], idx, n, v1, v);
            v.pop_back();
        }
        //v.push_back(candidates[idx]);
        helper(candidates, target, idx+1, n, v1, v);
        //v.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>> v1;
        vector<int> v;
        helper(candidates, target, 0, n, v1, v);
        return v1;
    }
};