class Solution {
public:
    bool dfs(int node, const vector<vector<int>>& adj, vector<int>& vis, vector<int>& samePath){
        vis[node]=1;
        samePath[node]=1;
        for(int x:adj[node]){
            if(vis[x]==0){
                if(dfs(x, adj, vis, samePath)==false)   return false;
            }
            else if(samePath[x]==1) return false;
        }
        samePath[node]=0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses,0), samePath(numCourses,0);
        for(auto x:prerequisites){
            adj[x[0]].push_back(x[1]);            
        }
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0){
                if(dfs(i, adj, vis, samePath)==false)   return false;
            }
        }
        return true;
    }
};