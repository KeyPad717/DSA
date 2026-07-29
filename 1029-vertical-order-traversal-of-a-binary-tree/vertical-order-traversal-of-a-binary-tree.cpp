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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)   return ans;
        map<int,map<int,multiset<int>>> mp; //{y,{x,multiset[]}}
        queue<pair<TreeNode*,pair<int,int>>> q;// {node,{x,y}}
        TreeNode* node=root;
        q.push({node,{0,0}});
        while(!q.empty()){
            node=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            mp[y][x].insert(node->val);
            if(node->left){
                q.push({node->left,{x+1,y-1}});
            }
            if(node->right){
                q.push({node->right,{x+1,y+1}});
            }
        }
        for(auto &a:mp){
            vector<int> temp;
            for(auto &b:a.second){
                for(auto c:b.second){
                    temp.push_back(c);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};