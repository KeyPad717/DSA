class Solution {
public:
    const int dr[4]={-1,1,0,0};
    const int dc[4]={0,0,-1,1};
    void dfs(int m, int n, int x, int y, vector<vector<char>>& grid){
        grid[x][y]='0';
        for(int i=0;i<4;i++){
            int c1=x+dr[i];
            int c2=y+dc[i];
            if(c1>=0 && c1<m && c2>=0 && c2<n && grid[c1][c2]=='1'){
                dfs(m,n,c1,c2,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size(), count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(m,n,i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};