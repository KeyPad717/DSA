/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*,TreeNode*> parentMap;
        unordered_map<TreeNode*, int> vis;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    parentMap[node->left]=node;
                }
                if(node->right){
                    q.push(node->right);
                    parentMap[node->right]=node;
                }
            }
        }
        int d=0;
        q.push(target);
        vis[target]=1;
        while(d!=k){
            d++;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                node=q.front();
                q.pop();
                if(parentMap.find(node)!=parentMap.end()){
                    if(vis.find(parentMap[node])==vis.end()){
                        vis[parentMap[node]]=1;
                        q.push(parentMap[node]);
                    }
                }
                if(node->left){
                    if(vis.find(node->left)==vis.end()){
                        vis[node->left]=1;
                        q.push(node->left);
                    }
                }
                if(node->right){
                    if(vis.find(node->right)==vis.end()){
                        vis[node->right]=1;
                        q.push(node->right);
                    }
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};