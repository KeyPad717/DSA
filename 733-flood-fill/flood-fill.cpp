class Solution {
public:
    const int dr[4]={0,0,-1,1};
    const int dc[4]={1,-1,0,0};
    void dfs(int m, int n, int sr, int sc, vector<vector<int>>& image, int color, const int fixed){
        image[sr][sc]=color;
        for(int i=0;i<4;i++){
            int x=sr+dr[i];
            int y=sc+dc[i];
            if(x>=0 && x<m && y>=0 && y<n && image[x][y]==fixed){
                dfs(m, n, x, y, image, color, fixed);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int fixed=image[sr][sc];
        if(image[sr][sc]!=color)
            dfs(image.size(), image[0].size(), sr, sc, image, color, fixed);
        return image;
    }
};