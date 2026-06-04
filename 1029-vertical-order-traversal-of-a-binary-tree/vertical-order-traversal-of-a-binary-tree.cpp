/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map < pair<int,int>, multiset<int> > mp;
        queue<pair<pair<int,int>,TreeNode*>> q;
        int row=0, col=0;
        TreeNode* temp=root;
        q.push({{row,col},root});
        while(!q.empty()){
            temp=q.front().second;
            row=q.front().first.first;
            col=q.front().first.second;
            q.pop();
            mp[{col,row}].insert(temp->val);
            if(temp->left)  q.push({{row+1,col-1},temp->left});
            if(temp->right)  q.push({{row+1,col+1},temp->right});
        }
        vector<int> v;
        int prevCol = INT_MIN;

        for(auto &x : mp){

            int currCol = x.first.first;

            if(currCol != prevCol){

                if(!v.empty())
                    res.push_back(v);

                v.clear();
                prevCol = currCol;
            }

            for(int val : x.second){
                v.push_back(val);
            }
        }

        if(!v.empty())
            res.push_back(v);
        return res;
    }
};