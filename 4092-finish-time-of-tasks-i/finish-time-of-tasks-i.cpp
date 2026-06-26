class Solution {
public:
    long long dfs(int node, const vector<vector<int>>& adj, const vector<int>& baseTime){
        if(adj[node].empty()){
            return baseTime[node];
        }
        long long latest=LLONG_MIN;
        long long earliest=LLONG_MAX;
        for(int x:adj[node]){
            long long child=dfs(x, adj, baseTime);
            latest=max(latest, child);
            earliest=min(earliest, child);
        }
        return 2*latest-earliest+baseTime[node];
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> adj(n);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
        }
        return dfs(0, adj, baseTime);
    }
};