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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)   return {};
        TreeNode* node=root;
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(node);
        while(!st.empty()){
            node=st.top();
            if(node!=nullptr) ans.push_back(node->val);
            st.pop();
            if(node!=nullptr) st.push(node->right);
            if(node!=nullptr) st.push(node->left);
        }
        return ans;
    }
};