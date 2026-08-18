class Solution {
public:
    int dc[4]={0,0,1,-1};
    int dr[4]={-1,1,0,0};
    void dfs(int x, int y, vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        grid[x][y]='0';
        for(int i=0;i<4;i++){
            int c1=x+dr[i];
            int c2=y+dc[i];
            if(c1>=0 && c2>=0 && c1<n && c2<m && grid[c1][c2]=='1'){
                dfs(c1,c2,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size(), islands=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    dfs(i,j,grid);
                }
            }
        }
        return islands;
    }
};