class Solution {
public:
    const vector<vector<int>> bound={{1,0}, {-1,0}, {0,1}, {0,-1}};
    void dfs(int m, int n, int x, int y, vector<vector<int>>& vis, const vector<vector<char>>& grid){
        for(int i=0;i<4;i++){
            int c1=x+bound[i][0];
            int c2=y+bound[i][1];
            if(c1>=0 && c1<m && c2>=0 && c2<n && grid[c1][c2]=='1' && vis[c1][c2]==0){
                vis[c1][c2]=1;
                dfs(m,n,c1,c2,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size(), count=0;
        vector<vector<int>> vis(m, vector<int> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    vis[i][j]=1;
                    dfs(m,n,i,j,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
};