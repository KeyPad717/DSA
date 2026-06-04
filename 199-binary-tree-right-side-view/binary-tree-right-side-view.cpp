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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)   return res;
        queue<TreeNode*> q;
        TreeNode* node=root;
        //vector<vector<int>> v;
        q.push(node);
        while(!q.empty()){
            int n=q.size();
            int p;
            //vector<int> temp;
            for(int i=0;i<n;i++){
                node=q.front();
                q.pop();
                //temp.push_back(node->val);
                p=node->val;
                if(node->left)  q.push(node->left);
                if(node->right)  q.push(node->right);
            }
            res.push_back(p);
        }
        return res;
    }
};