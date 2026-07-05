class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<pair<int,int>> coord;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0)    coord.push_back({i,j});
            }
        }
        for(auto x:coord){
            int r=x.first;
            int c=x.second;
            for(int i=0;i<n;i++){
                matrix[r][i]=0;
            }
            for(int i=0;i<m;i++){
                matrix[i][c]=0;
            }
        }
    }
};