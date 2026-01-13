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
    
    // void helper(TreeNode* root){
    //     if(root==nullptr) return;
    //     v.push_back(root->val);
    //     helper(root->left);
    //     helper(root->right);
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root==nullptr)   return v;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* temp=new TreeNode();
            temp=s.top();
            v.push_back(temp->val);
            s.pop();
            if(temp->right==nullptr && temp->left==nullptr) continue;
            if(temp->right==nullptr){
                s.push(temp->left);
                continue;
            } 
            if(temp->left==nullptr){
                s.push(temp->right);
                continue;
            } 
            s.push(temp->right);
            s.push(temp->left);
        }
        return v;
    }
};