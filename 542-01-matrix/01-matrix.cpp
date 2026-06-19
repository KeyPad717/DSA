class Solution {
public:
    const int dr[4]={0,0,-1,1};
    const int dc[4]={1,-1,0,0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> mat1(m, vector<int> (n,0));
        vector<vector<int>> vis(m, vector<int> (n,0));
        queue<pair<pair<int,int>, int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            int step=q.front().second;
            int c1=q.front().first.first;
            int c2=q.front().first.second;
            mat1[c1][c2]=step;
            q.pop();
            //cout<<c1<<" "<<c2<<" "<<step<<endl;
            for(int i=0;i<4;i++){
                int x=c1+dr[i];
                int y=c2+dc[i];
                if(x>=0 && x<m && y>=0 && y<n && mat[x][y]!=0 && vis[x][y]==0){
                    q.push({{x,y},step+1});
                    vis[x][y]=1;
                }
            }
        }
        return mat1;
    }
};