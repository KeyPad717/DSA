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
        vector<int> res;
        if(!root)   return res;
        deque<TreeNode*> q;
        q.push_back(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop_front();
            res.push_back(temp->val);
            if(temp->right)  q.push_front(temp->right);
            if(temp->left)  q.push_front(temp->left);
            
        }
        return res;
    }
};