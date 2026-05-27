class Solution {
public:
    const vector<vector<int>> bound{{0,1}, {0,-1}, {1,0}, {-1,0}};
    void check(vector<vector<char>>& board, string& word, int idx, int sz, int n, int m, int sz1, int sz2, bool& ans){
        if(idx == sz){
            ans = true;
            return;
        }

        if(ans)
            return;
        for(int i=0;i<4;i++){
            int row=n+bound[i][0];
            int col=m+bound[i][1];
            if(row>=0 && row<sz1 && col>=0 && col<sz2 && board[row][col]!='#'){
                if(board[row][col]==word[idx]){
                    char temp=board[row][col];
                    board[row][col]='#';
                    check(board, word, idx+1, sz, row, col, sz1, sz2, ans);
                    if(ans==true)   return ;
                    board[row][col]=temp;
                }
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<int> boardFreq(128, 0);
        vector<int> wordFreq(128, 0);
        int n=board.size(), m=board[0].size(), sz=word.size();
        bool ans=false;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                boardFreq[board[i][j]]++;
        for(char c : word)
            wordFreq[c]++;
        for(int i=0;i<128;i++){
            if(boardFreq[i] < wordFreq[i])
                return false;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    char temp=board[i][j];
                    board[i][j]='#';
                    check(board, word, 1, sz, i, j, n, m, ans);
                    if(ans) return true;
                    board[i][j]=temp;
                }
            }
        }
        return ans;
    }
};