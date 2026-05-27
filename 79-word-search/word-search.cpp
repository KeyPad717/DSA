class Solution {
public:
    void check(vector<vector<char>>& board, string word, int idx, int sz, int n, int m, int sz1, int sz2, bool& ans, vector<vector<int>> bound, vector<vector<int>>& vis){
        if(idx==sz){
            ans=true;
            return ;
        }
        for(int i=0;i<4;i++){
            int row=n+bound[i][0];
            int col=m+bound[i][1];
            if(row>=0 && row<sz1 && col>=0 && col<sz2 && vis[row][col]==-1){
                if(board[row][col]==word[idx]){
                    vis[row][col]=1;
                    check(board, word, idx+1, sz, row, col, sz1, sz2, ans, bound, vis);
                    if(ans==true)   return ;
                    vis[row][col]=-1;
                }
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        unordered_map<char,int> boardFreq;
        unordered_map<char,int> wordFreq;
        int n=board.size(), m=board[0].size(), sz=word.size();
        bool ans=false;
        vector<vector<int>> bound{{0,1}, {0,-1}, {1,0}, {-1,0}};
        vector<vector<int>> vis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                boardFreq[board[i][j]]++;
        for(int i=0;i<sz;i++)    wordFreq[word[i]]++;
        for(auto &x : wordFreq){
            if(boardFreq[x.first] < x.second)
                return false;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=1;
                    check(board, word, 1, sz, i, j, n, m, ans, bound, vis);
                    if(ans) return true;
                    vis[i][j]=-1;
                }
            }
        }
        return ans;
    }
};