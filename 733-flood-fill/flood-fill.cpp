class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int tar=image[sr][sc];
        if(tar==color)  return image;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int adj[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int a=q.front().first;
            int b=q.front().second;
            //cout<<a<<" "<<b<<endl;
            q.pop();
            image[a][b]=color;
            for(int i=0;i<4;i++){
                int x=a+adj[i][0];
                int y=b+adj[i][1];
                if(x>=0 && y>=0 && x<m && y<n && image[x][y]==tar){
                    image[x][y]=color;
                    q.push({x,y});
                }
            }
        }
        return image;
    }
};