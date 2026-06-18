class Solution {
public:
    const int dr[4]={0,0,-1,1};
    const int dc[4]={1,-1,-0,0};
    void dfs1(int c1, int c2, int m, int n, vector<vector<char>>& board){
        board[c1][c2]='P';
        for(int i=0;i<4;i++){
            int x=c1+dr[i];
            int y=c2+dc[i];
            if(x>0 && x<m-1 && y>0 && y<n-1 && board[x][y]=='O'){
                
                dfs1(x,y,m,n,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || i==m-1 || j==0 || j==n-1) && board[i][j]=='O'){
                    dfs1(i,j,m,n,board);
                }
            } 
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //if(i>0 && i<m-1 && j>0 && j<n-1){
                    if(board[i][j]=='P'){
                        board[i][j]='O';
                    }
                    else if(board[i][j]=='O'){
                        board[i][j]='X';
                    }
                //}
            } 
        }
    }
};