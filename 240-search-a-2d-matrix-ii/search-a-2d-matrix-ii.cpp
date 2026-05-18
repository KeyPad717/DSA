    class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int n=matrix.size(), m=matrix[0].size(), col=-1, row=-1;
            int x=0, y=m-1;
            while(x<n && y>=0){
                if(target==matrix[x][y])       return true;
                if(target>matrix[x][y]){
                    x++;
                }
                else{
                    y--;
                }
            }
            return false;
        }
    };