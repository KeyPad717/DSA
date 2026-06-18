class Solution {
public:
    const int dr[4]={0,0,-1,1};
    const int dc[4]={-1,1,0,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int maxtime=0, count;
        queue<pair<pair<int,int>, int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                if(grid[i][j]==1)   count++;
            }
        }
        if(count==0)    return -1;
        while(!q.empty()){
            int c1=q.front().first.first;
            int c2=q.front().first.second;
            int time=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int x=c1+dr[i];
                int y=c2+dc[i];
                if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==1){
                    grid[x][y]=2;
                    q.push({{x,y},time+1});
                }
            }
            maxtime=max(maxtime,time);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)   return -1;
            }
        }
        return maxtime;
    }
};