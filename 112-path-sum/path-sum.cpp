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
    int sum1=0;
    bool inorder(TreeNode* root,int curSum, int targetSum){
        if(root==nullptr)   return false;
        curSum+=root->val;
        if(root->left==nullptr && root->right==nullptr){
            return(curSum==targetSum); 
        }
        return(inorder(root->left,curSum,targetSum)||inorder(root->right,curSum,targetSum));
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return(inorder(root,0,targetSum));
    }
};