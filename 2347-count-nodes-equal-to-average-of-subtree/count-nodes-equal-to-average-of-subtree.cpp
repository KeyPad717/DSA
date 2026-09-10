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
    int ans=0;
    pair<int,int> helper(TreeNode* node){
        if(!node)   return {0,0};
        if(!node->left && !node->right){
            ans++;
            return {node->val,1};
        }
        pair<int,int> left=helper(node->left);
        pair<int,int> right=helper(node->right);
        int lsum=left.first;
        int rsum=right.first;
        int lcount=left.second;
        int rcount=right.second;
        if((lsum+rsum+node->val)/(lcount+rcount+1)==node->val){
            ans++;
        }
        return {lsum+rsum+node->val,lcount+rcount+1};
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return ans;
    }
};