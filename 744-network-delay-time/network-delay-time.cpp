class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int maxi=INT_MIN;
        vector<vector<pair<int,int>>> adj(n+1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
        vector<int> dist(n+1,1e9);
        for(auto x:times){
            adj[x[0]].push_back({x[1],x[2]});
        }
        heap.push({0,k});
        dist[k]=0;
        while(!heap.empty()){
            int d=heap.top().first;
            int node=heap.top().second;
            heap.pop();
            if(d!=dist[node])   continue;
            for(auto x:adj[node]){
                if(d+x.second<dist[x.first]){
                    dist[x.first]=d+x.second;
                    heap.push({dist[x.first], x.first});
                }
            }
        }
        for(int i=1;i<n+1;i++){
            if(dist[i]==1e9)    return -1;
            maxi=max(maxi,dist[i]);
        }
        return maxi;
    }
};