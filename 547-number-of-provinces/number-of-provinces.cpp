class Solution {
public:
    void helper(int node, const vector<vector<int>>& adj, vector<int>& vis){
        vis[node]=1;
        for(int x:adj[node]){
            if(vis[x]==0){
                vis[x]=1;
                helper(x, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int V=isConnected.size();
        vector<vector<int>> adj(V);
        vector<int> vis(V,0);
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(i!=j && isConnected[i][j]==1)    adj[i].push_back(j);
            }
        }
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                helper(i, adj, vis);
                count++;
            }
        }
        return count;
    }
};