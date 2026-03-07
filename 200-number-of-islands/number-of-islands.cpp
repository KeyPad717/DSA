class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), count=0;
        int n=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n, -1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && vis[i][j]==-1){
                    q.push({i,j});
                    int adj[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
                    while(!q.empty()){
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();
                        vis[x][y]=1;
                        for(int k=0;k<4;k++){
                            int a=x+adj[k][0];
                            int b=y+adj[k][1];
                            if(a>=0 && b>=0 && a<m && b<n && grid[a][b]=='1' && vis[a][b]==-1){
                                q.push({a,b});
                                vis[a][b]=1;
                            }
                        }
                    }
                    count++;
                }
            }
            
        }
        return count;
    }
};