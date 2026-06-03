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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)   return res;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        TreeNode* node=root;
        st1.push(node);
        while(!st1.empty()){
            node=st1.top();
            st2.push(node);
            st1.pop();
            if(node->left)   st1.push(node->left);
            if(node->right)   st1.push(node->right);
        }
        while(!st2.empty()){
            node=st2.top();
            res.push_back(node->val);
            st2.pop();
        }
        return res;
    }
};