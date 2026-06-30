class Solution {
public:
    const int dr[8]={0,0,1,-1,1,-1,1,-1};
    const int dc[8]={1,-1,0,0,1,-1,-1,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1)   return -1;
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int> (n,0));
        q.push({0,0});
        grid[0][0]=1;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x==n-1 && y==n-1){
                return dist[x][y]+1;
            }
            for(int i=0;i<8;i++){
                int c1=dr[i]+x;
                int c2=dc[i]+y;
                if(c1>=0 && c1<n && c2>=0 && c2<n && grid[c1][c2]==0){
                    grid[c1][c2]=1;
                    dist[c1][c2]=dist[x][y]+1;
                    q.push({c1,c2});
                }
            }
        }
        return -1;
    }
};