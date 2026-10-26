class Solution {
public:
    int m,n;
    int dr[4]={0,0,-1,1};
    int dc[4]={-1,1,0,0};
    
    void dfs(int i, int j, vector<vector<int>>& grid, int k, long long& sum){
        if(i<0 || j<0 || i>=n || j>=m)  return;
        if(grid[i][j]==0)   return;
        sum+=grid[i][j];
        grid[i][j]=0;
        dfs(i, j-1, grid, k, sum);
        dfs(i, j+1, grid, k, sum);
        dfs(i+1, j, grid, k, sum);
        dfs(i-1, j, grid, k, sum);
        return;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    long long sum=0;
                    dfs(i,j,grid,k,sum);
                    if(sum!=0 && (sum%k)==0)  cnt++;
                }
            }
        }
        return cnt;
    }
};