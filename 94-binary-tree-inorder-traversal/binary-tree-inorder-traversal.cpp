class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)   return {};
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node=root;
        while(true){
            if(node){
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty())  break;
                node=st.top();
                ans.push_back(st.top()->val);
                st.pop();
                node=node->right;
            }
        }
        return ans;
    }
};