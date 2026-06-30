class Solution {
public:
    const int dr[8]={0,0,1,-1,1,-1,1,-1};
    const int dc[8]={1,-1,0,0,1,-1,-1,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1)   return -1;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        while(!q.empty()){
            int dist=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            grid[x][y]=1;
            if(x==n-1 && y==n-1){
                return dist+1;
            }
            for(int i=0;i<8;i++){
                int c1=dr[i]+x;
                int c2=dc[i]+y;
                if(c1>=0 && c1<n && c2>=0 && c2<n && grid[c1][c2]==0){
                    grid[c1][c2]=1;
                    q.push({dist+1,{c1,c2}});
                }
            }
        }
        return -1;
    }
};