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
    int height(TreeNode* root, int& maxi){
        if(!root)   return 0;
        int lh=height(root->left, maxi);
        int rh=height(root->right, maxi);
       // cout<<root->val<<" "<<maxi<<" "<<lh<<" "<<rh<<endl;
        maxi=max(maxi,lh+rh);
        //cout<<root->val<<" "<<maxi<<" "<<lh<<" "<<rh<<endl;
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=INT_MIN;
        height(root,maxi);
        return maxi;
    }
};