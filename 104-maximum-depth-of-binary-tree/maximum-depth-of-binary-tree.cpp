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
    int maxHelper(TreeNode* root, int len){
        if(!root)   return 0;
        if(!root->left && !root->right) return len;
        else if (!root->left)   return maxHelper(root->right, len+1);
        else if (!root->right)   return maxHelper(root->left, len+1);
        return max(maxHelper(root->left, len+1), maxHelper(root->right, len+1));
    }
    int maxDepth(TreeNode* root) {
        return maxHelper(root, 1);
    }
};