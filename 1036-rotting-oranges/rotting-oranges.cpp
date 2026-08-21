class Solution {
public:
    int dr[4]={0,0,-1,1};
    int dc[4]={1,-1,0,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size(), cnt=0, time=0;
        queue<pair<pair<int,int>,int>> q;//{{x,y},time}
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)   q.push({{i,j},0});
                if(grid[i][j]==1)   cnt++;
            }
        }
        if(cnt==0)  return 0;
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int t=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int c1=x+dr[i];
                int c2=y+dc[i];
                if(c1>=0 && c2>=0 && c1<n && c2<m && grid[c1][c2]==1){
                    grid[c1][c2]=2;
                    q.push({{c1,c2},t+1});
                    cnt--;
                }
            }
            time=max(time,t);
        }
        if(cnt!=0)  return -1;
        return time;
    }
};