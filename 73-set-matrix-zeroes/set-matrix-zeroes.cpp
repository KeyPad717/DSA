class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size(), col=matrix[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    //cout<<i<<" "<<j<<" "<<matrix[i][j]<<endl;
                    if(i==0 && j==0){
                        col=0;
                        matrix[i][j]=0;
                    }
                    else if(j==0){
                        col=0;
                    }
                    else if(i==0){
                        matrix[0][0]=0;
                    }
                    else{
                        matrix[0][j]=0;
                        matrix[i][0]=0;
                    }
                }
            }
        }
        for(int i=m-1;i>0;i--){
            for(int j=n-1;j>0;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0){
            for(int j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }
        if(col==0){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};



























