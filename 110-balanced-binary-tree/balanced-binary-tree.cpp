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
        //if(root->left==nullptr && root->left==nullptr) return 0;
        int leftH=0, rightH=0;
        if(root->left)  leftH=solver(root->left);
        if(root->right) rightH=solver(root->right);
        if(leftH==-1||rightH==-1)   return -1;
        if(abs(leftH-rightH)>1)     return -1;
        return(max(leftH,rightH)+1);
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)   return true;
        int x=solver(root);
        if(x!=-1)   return true;
        return false;
    }
};