class DisjointSet{
    public:
        vector<int> size, parent;
        DisjointSet(int n){
            size.resize(n+1);
            parent.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
                size[i]=1;
            }
        }
        int findUPar(int node){
            if(parent[node]==node)  return node;
            parent[node]=findUPar(parent[node]);
            return parent[node];
        }
        bool unionBySize(int u, int v){
            int ult_u=findUPar(u);
            int ult_v=findUPar(v);
            if(ult_u==ult_v)    return false;
            if(size[ult_u]>size[ult_v]){
                parent[ult_v]=ult_u;
                size[ult_u]+=size[ult_v];
            }
            else{
                parent[ult_u]=ult_v;
                size[ult_v]+=size[ult_u];
            }
            return true;
        }
};
class Solution {
public:
    int dr[4]={0,0,-1,1};
    int dc[4]={1,-1,0,0};
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size(), maxi=0, f=0;
        if(n==1)    return 1;
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int ele1=i*n+j;
                    for(int k=0;k<4;k++){
                        int x=i+dr[k];
                        int y=j+dc[k];
                        if(x>=0 && y>=0 && x<n && y<n && grid[x][y]==1){
                            int ele2=x*n+y;
                            ds.unionBySize(ele1,ele2);
                        }
                    }
                }
            }
        }
        for(int i=0;i<n*n;i++){
            ds.findUPar(i);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    f++;
                    set<int> st;
                    int sum=0;
                    int ele1=i*n+j;
                    for(int k=0;k<4;k++){
                        int x=i+dr[k];
                        int y=j+dc[k];
                        if(x>=0 && y>=0 && x<n && y<n && grid[x][y]==1){
                            int ele2=x*n+y;
                            st.insert(ds.parent[ele2]);
                        }
                    }
                    for(int x:st){
                        sum+=ds.size[x];
                    }
                    sum++;
                    maxi=max(maxi,sum);
                }
            }
        }
        if(f==0)    return n*n;
        return maxi;
    }
};