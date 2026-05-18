class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size(),x=-1,y=-1;
        if(n==1 && m==1)    return {0,0};
        int left=0, right=m-1;
        //vector<vector<int>> v = {{0,1},{0,-1}};        
        while(1){
            int mid=left+(right-left)/2, maxi=-1;
            for(int i=0;i<n;i++){
                if(mat[i][mid]>maxi){
                    maxi=mat[i][mid];
                    x=i;
                    y=mid;
                }
            }
            if(y>=1 && y<=m-2){
                if(mat[x][y]>mat[x][y-1] && mat[x][y]>mat[x][y+1]){
                    return {x,y};
                }
                else if (mat[x][y]>mat[x][y-1]) left=mid+1;
                else                            right=mid-1;
            }
            else if (y==0){
                if(mat[x][y]>mat[x][y+1])   return {x,y};
                else                        left=mid+1;
            }
            else{
                if(mat[x][y]>mat[x][y-1])   return {x,y};
                else                        right=mid-1;
            }
        }
        return {x,y};
    }
};