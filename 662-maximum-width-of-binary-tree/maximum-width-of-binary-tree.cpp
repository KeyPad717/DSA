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
        queue<pair<TreeNode*,int>> q; // {node,index}
        int maxi=0;
        q.push({root,0});
        TreeNode* node;
        while(!q.empty()){
            int sz=q.size(), low, high;
            int min_idx=q.front().second;
            for(int i=0;i<sz;i++){
                node=q.front().first;
                long long idx=q.front().second - min_idx;
                q.pop();
                if(i==0)   low=idx;
                if(i==sz-1) high=idx; 
                if(node->left)  q.push({node->left,idx*2LL+1});
                if(node->right)  q.push({node->right,idx*2LL+2});
            }
            maxi=max(maxi,high-low+1);
        }
        return maxi;
    }
};