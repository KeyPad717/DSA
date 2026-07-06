class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<matrix[i].size();j++){
                if(i<j){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
        int l=0, r=m-1;
        while(l<r){
            for(int i=0;i<n;i++){
                swap(matrix[i][l], matrix[i][r]);
            }
            l++;
            r--;
        }
    }
};