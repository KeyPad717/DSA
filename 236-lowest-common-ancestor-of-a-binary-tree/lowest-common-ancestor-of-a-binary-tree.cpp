/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* node, TreeNode* p, TreeNode* q){
        if(!node)   return nullptr;
        if(node==p || node==q) return node;
        TreeNode* left=dfs(node->left,p,q);
        TreeNode* right=dfs(node->right,p,q);
        if(left && right)   return node;
        if(!left)           return right;
        if(!right)          return left;
        return nullptr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};