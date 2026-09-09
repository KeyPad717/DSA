class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> seen(10,false);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(seen[board[i][j]-'0']==false){
                        seen[board[i][j]-'0']=true;
                    }
                    else    return false;
                }
            }
            fill(seen.begin(), seen.end(), false);
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    if(seen[board[j][i]-'0']==false){
                        seen[board[j][i]-'0']=true;
                    }
                    else    return false;
                }
            }
            fill(seen.begin(), seen.end(), false);
        }
        for(int br = 0; br < 9; br++) {
            int startRow = (br / 3) * 3;
            int startCol = (br % 3) * 3;
            for(int i=startRow;i<startRow+3;i++){
                for(int j=startCol;j<startCol+3;j++){
                    if(board[i][j]!='.'){
                        if(seen[board[i][j]-'0']==false){
                            seen[board[i][j]-'0']=true;
                        }
                        else    return false;
                    }
                }
            }
            fill(seen.begin(), seen.end(), false);
        }        
        return true;
    }
};