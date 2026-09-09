class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int> mp;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(mp.find(board[i][j])==mp.end()){
                        mp[board[i][j]]++;
                    }
                    else    return false;
                }
            }
            mp.clear();
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    if(mp.find(board[j][i])==mp.end()){
                        mp[board[j][i]]++;
                    }
                    else    return false;
                }
            }
            mp.clear();
        }
        for(int br = 0; br < 9; br++) {
            int startRow = (br / 3) * 3;
            int startCol = (br % 3) * 3;
            for(int i=startRow;i<startRow+3;i++){
                for(int j=startCol;j<startCol+3;j++){
                    if(board[i][j]!='.'){
                        if(mp.find(board[i][j])==mp.end()){
                            mp[board[i][j]]++;
                        }
                        else    return false;
                    }
                }
            }
            mp.clear();
        }        
        return true;
    }
};