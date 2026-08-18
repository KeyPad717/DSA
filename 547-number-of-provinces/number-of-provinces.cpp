class Solution {
public:
    void dfs(int node, const vector<vector<int>>& isConnected, vector<int>& vis){
        vis[node]=1;
        for(int j=0;j<isConnected.size();j++){
            if(j!=node && isConnected[node][j]==1 && vis[j]==0){
                dfs(j,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(), prov=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                prov++;
                dfs(i,isConnected,vis);
            }
        }
        return prov;
    }
};