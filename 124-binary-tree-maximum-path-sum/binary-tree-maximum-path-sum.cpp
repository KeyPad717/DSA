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
    int depth(TreeNode* root, int& maxi){
        if(!root)   return 0;
        int lh=depth(root->left, maxi);
        int rh=depth(root->right, maxi);
        if(lh<=0 && rh<=0)  {
            maxi=max(maxi,root->val);
            return root->val;
        }
        else if(lh<=0){
            maxi=max(maxi,root->val+rh);
            return root->val+rh;
        }
        else if(rh<=0){
            maxi=max(maxi,root->val+lh);
            return root->val+lh;
        }
        maxi=max(maxi, lh+rh+root->val);
        return root->val+max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        depth(root, maxi);
        return maxi;
    }
};