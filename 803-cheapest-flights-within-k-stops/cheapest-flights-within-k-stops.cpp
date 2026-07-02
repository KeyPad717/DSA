class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        queue<pair<int,pair<int,int>>> q;//stops, node, dist
        vector<int> dist(n,1e9);
        for(auto x:flights){
            adj[x[0]].push_back({x[1],x[2]});
        }
        q.push({0,{src,0}});
        dist[src]=0;
        while(!q.empty()){
            auto it=q.front();
            int stops=it.first;
            int node=it.second.first;
            int dist1=it.second.second;
            q.pop();
            if(stops>k){
                break;
            }
            for(auto x:adj[node]){
                int node1=x.first;
                int edge=x.second;
                if(edge+dist1<dist[node1]){
                    dist[node1]=edge+dist1;
                    q.push({stops+1, {node1, dist[node1]}});
                }
            }
        }
        return dist[dst]==1e9?-1:dist[dst];
    }
};