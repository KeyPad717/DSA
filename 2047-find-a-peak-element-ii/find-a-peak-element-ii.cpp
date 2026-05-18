class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int x=0, y=0, n=mat.size(), m=mat[0].size();
        vector<vector<int>> v = {{0,1},{0,-1},{1,0},{-1,0}};        
        while(1){
            int maxi=mat[x][y],f=0;
            for(int i=0;i<4;i++){
                int row=x+v[i][0];
                int col=y+v[i][1];
                if(row>=0 && row<n && col>=0 && col<m){
                    if(mat[row][col]>maxi){
                        f++;
                        x=row;
                        y=col;
                        maxi=mat[row][col];
                    }
                }
            }
            if(f==0)    return{x,y};
        }
        return {x,y};
    }
};