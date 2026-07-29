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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        TreeNode* node=root;
        int maxi=0;
        q.push({node,0});
        while(!q.empty()){
            int sz=q.size();
            int min_idx=q.front().second;
            int firstIdx=0, secondIdx=0;
            for(int i=0;i<sz;i++){
                node=q.front().first;
                int idx=q.front().second-min_idx;
                if(i==0)  firstIdx=idx;
                if(i==sz-1) secondIdx=idx;
                q.pop();
                if(node->left)  q.push({node->left,2LL*(idx)+1});
                if(node->right)  q.push({node->right,2LL*(idx)+2});
            }
            maxi=max(maxi,secondIdx-firstIdx+1);
        }
        return maxi;
    }
};