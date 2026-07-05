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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int res=0, rem=0, temp=0, count=0;
        DisjointSet ds(n);
        for(auto x:connections){
            int u=x[0];
            int v=x[1];
            if(!ds.unionByRank(u,v))    temp++;
        }
        for(int i=0;i<n;i++){
            ds.findUpar(i);
        }
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                count++;
            }
        }
        count--;
        cout<<temp<<" "<<count<<endl;
        if(temp>=count)    return count;
        return -1;
    }
};