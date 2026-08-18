class Solution {
public:
    void dfs(int node, const vector<vector<int>>& adj, vector<int>& vis){
        vis[node]=1;
        for(int j:adj[node]){
            if(vis[j]==0){
                dfs(j,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(), prov=0;
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                prov++;
                dfs(i,adj,vis);
            }
        }
        return prov;
    }
};