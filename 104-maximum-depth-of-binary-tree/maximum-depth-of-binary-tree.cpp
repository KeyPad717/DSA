/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solver(TreeNode* root){
        if(root==nullptr)    return 0;
        if(root->left==nullptr && root->right==nullptr) return 1;
        if(root->left==nullptr) return 1+solver(root->right);
        if(root->right==nullptr) return 1+solver(root->left);     
        return 1+max(solver(root->right),solver(root->left));
    }
    int maxDepth(TreeNode* root) {
        if(root==nullptr)   return 0;
        return 1+max(solver(root->left),solver(root->right));
    }
};