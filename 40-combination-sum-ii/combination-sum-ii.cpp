class Solution {
public:
    void helper(vector<int>& candidates, int target, int idx, int n, vector<vector<int>>& v1, vector<int>& v){
        if(target==0){
            v1.push_back(v);
            return ;
        }
        if(idx>=n)  return ;
        
        for(int i = idx; i < n; i++) {
            if(i > idx && candidates[i] == candidates[i-1])
                continue;
            if(candidates[i] > target)
                break;
            v.push_back(candidates[i]);
            helper(candidates, target - candidates[i], i + 1, n, v1, v);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n=candidates.size();
        vector<vector<int>> v1;
        vector<int> v;
        helper(candidates, target, 0, n, v1, v);
        return v1;
    }
};