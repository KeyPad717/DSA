class Solution {
public:
    long long dfs(int node, long long& finish, long long latest, long long earliest, const vector<vector<int>>& adj, const vector<int>& baseTime, vector<int>& vis){
        vis[node]=1;
        if(adj[node].empty()){
            return baseTime[node];
        }
        for(int x:adj[node]){
            if(vis[x]==0){
                long long child=dfs(x, finish, LLONG_MIN, LLONG_MAX, adj, baseTime, vis);
                latest=max(latest, child);
                earliest=min(earliest, child);
            }
        }
        finish=2*latest-earliest+baseTime[node];
        return finish;
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
        }
        long long finish=0;
        return dfs(0, finish, LLONG_MIN, LLONG_MAX, adj, baseTime, vis);
    }
};