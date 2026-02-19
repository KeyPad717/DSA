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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr)   return {};
        vector<vector<int>> v1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> v;
            int n=q.size();
            TreeNode* temp=new TreeNode();
            while(n--){
                temp=q.front();
                if(temp->left==nullptr && temp->right==nullptr){
                    v.push_back(temp->val);
                    q.pop();
                    continue;
                }
                if(temp->left==nullptr){
                    q.push(temp->right);
                    v.push_back(temp->val);
                    q.pop();
                    continue;
                }
                if(temp->right==nullptr){
                    q.push(temp->left);
                    v.push_back(temp->val);
                    q.pop();
                    continue;
                }
                q.push(temp->left);
                q.push(temp->right);
                v.push_back(temp->val);
                q.pop();
            }
            v1.push_back(v);
        }
        return v1;
    }
};