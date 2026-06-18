class Solution {
public:
    const int dr[4]={0,0,1,-1};
    const int dc[4]={1,-1,0,0};
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), total=0, walk=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(i==0 || i==m-1 || j==0 || j==n-1){
                        q.push({i,j});
                        grid[i][j]=0;
                    }
                    else{
                        total++;
                    }
                }
            }
        }
        while(!q.empty()){
            int c1=q.front().first;
            int c2=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int x=c1+dr[i];
                int y=c2+dc[i];
                if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==1){
                    grid[x][y]=0;
                    q.push({x,y});
                    walk++;
                }
            }
        }
        return total-walk;
    }
};