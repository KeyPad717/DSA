class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>> adj(n);
        vector<long long> dist(n,LLONG_MAX);
        vector<long long> ways(n,0LL);
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> heap;
        for(auto x:roads){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        heap.push({0,0});
        dist[0]=0;
        ways[0]=1;
        while(!heap.empty()){
            long long dist1=heap.top().first;
            long long node=heap.top().second;
            heap.pop();
            if(dist1!=dist[node])   continue;
            for(auto x:adj[node]){
                long long node1=x.first;
                long long edge=x.second;
                if(edge+dist[node]<dist[node1]){
                    dist[node1]=edge+dist[node];
                    heap.push({dist[node1],node1});
                    ways[node1]=ways[node];
                }
                else if(edge+dist[node]==dist[node1]){
                    long long a=ways[node1]%1000000007;
                    long long b=ways[node]%1000000007;
                    ways[node1]=a+b;
                    ways[node1]=ways[node1]%1000000007;
                }
            }
        }
        return (ways[n-1])%1000000007;
    }
};