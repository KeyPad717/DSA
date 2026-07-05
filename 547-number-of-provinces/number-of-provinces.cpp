class DisjointSet{
    public:
        vector<int> rank, parent;
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        int findUpar(int node){
            if(node==parent[node])  return node;
            parent[node]=findUpar(parent[node]);
            return parent[node];
        }
        bool unionByRank(int u, int v){
            int ult_u=findUpar(u);
            int ult_v=findUpar(v);
            if(ult_u==ult_v)    return false;
            if(rank[ult_u]<rank[ult_v]){
                parent[ult_u]=ult_v;
            }
            else if(rank[ult_v]<rank[ult_u]){
                parent[ult_v]=ult_u;
            }
            else{
                parent[ult_v]=ult_u;
                rank[ult_u]++;
            }
            return true;
        } 
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DisjointSet ds(n);
        //vector<pair<int,int>> edges;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    ds.unionByRank(i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            ds.findUpar(i);
        }
        for(int i=0;i<n;i++){
            if(i==ds.parent[i])  count++;
        }
        return count;
    }
};