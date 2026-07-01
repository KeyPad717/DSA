class Solution {
public:
    int dr[4]={0,0,1,-1};
    int dc[4]={-1,1,0,0};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r=heights.size(), c=heights[0].size(), maxi=INT_MIN;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
                        greater<pair<int,pair<int,int>>>> q;
        vector<vector<int>> dist(r, vector<int> (c,INT_MAX));
        q.push({0,{0,0}});  
        dist[0][0]=0;
        while(!q.empty()){
            int d=q.top().first;
            int x=q.top().second.first;
            int y=q.top().second.second;
            q.pop();
            if(x==r-1 && y==c-1){
                return d;
            }
            //if(d!=dist[x][y])   continue;
            for(int i=0;i<4;i++){
                int c1=dr[i]+x;
                int c2=dc[i]+y;
                if(c1>=0 && c1<r && c2>=0 && c2<c){
                    int newEff=max(d, abs(heights[c1][c2]-heights[x][y]));
                    if(newEff<dist[c1][c2]){
                        dist[c1][c2]=newEff;
                        q.push({dist[c1][c2],{c1,c2}});
                    }
                }
            }
        }
        return -1;
    }
};