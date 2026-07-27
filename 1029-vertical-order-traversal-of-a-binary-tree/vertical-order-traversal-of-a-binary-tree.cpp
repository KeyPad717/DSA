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
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> mp;
        q.push({root,{0,0}});
        TreeNode* node;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                node=q.front().first;
                int x=q.front().second.first;
                int y=q.front().second.second;
                q.pop();
                if(node->left)  q.push({node->left,{x+1,y-1}});
                if(node->right)  q.push({node->right,{x+1,y+1}});
                mp[y][x].insert(node->val);
            }
        }
        for(auto x:mp){
            vector<int> temp;
            for(auto y:x.second){
                temp.insert(temp.end(),y.second.begin(),y.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};