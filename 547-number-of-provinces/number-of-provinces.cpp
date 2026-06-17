class Solution {
public:
    void helper(int row, const vector<vector<int>>& isConnected, vector<int>& vis){
        vis[row]=1;
        for(int x=0;x<isConnected.size();x++){
            if(row!=x && isConnected[row][x]==1){
                if(vis[x]==0){
                    helper(x,isConnected,vis);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int V=isConnected.size();
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1){
                    if(vis[i]==0){
                        count++;
                        helper(i,isConnected,vis);
                    }
                }
            }
        }
        return count;
    }
};