class Solution {
public:
    void dfs(TreeNode* node, vector<int>& ans){
        if(!node)   return;
        ans.push_back(node->val);
        dfs(node->left,ans);
        dfs(node->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)   return {};
        vector<int> ans;
        dfs(root,ans);
        return ans;
    }
};