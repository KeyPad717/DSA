class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)   return {};
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top();
            ans.push_back(node->val);
            st.pop();
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return ans;
    }
};