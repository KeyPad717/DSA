class Solution {
public:
    bool safety(int row, int col, vector<string>& board, int n){
        int r=row, c=col;
        while(row>=0 && row<n && col>=0 && col<n){
            if(board[row][col]=='Q')    return false;
            row--;
            col--;
        }
        row=r;
        col=c;
        while(col>=0 && col<n){
            if(board[row][col]=='Q')    return false;
            col--;
        }
        row=r;
        col=c;
        while(row>=0 && row<n && col>=0 && col<n){
            if(board[row][col]=='Q')    return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col, vector<string>& board, vector<vector<string>>& res, int n){
        if(col==n){
            res.push_back(board);
            return ;
        }
        for(int row=0;row<n;row++){
            if(safety(row, col,board, n)){
                board[row][col]='Q';
                solve(col+1,board, res, n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board;
        string s(n,'.');
        for(int i=0;i<n;i++)    board.push_back(s);
        solve(0,board, res, n);
        return res;
    }
};