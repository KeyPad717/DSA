class Solution {
public:
    int count=0;
    void helper(int node, vector<vector<int>>& isConnected, vector<int>& vis){
        vis[node]=1;
        //cout<<node<<endl;
        
        int n=isConnected.size();
        for(int i=0;i<n;i++){
            //cout<<node-1<<" "<<i+1<<" "<<isConnected[node-1][i]<<endl;
            if(!vis[i+1] && isConnected[node-1][i]==1){
                
                helper(i+1, isConnected, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size()+1;
        vector<int> vis(n,0);
        for(int i=1;i<n;i++){
            if(!vis[i]){
                count++;
                helper(i, isConnected, vis);
            }
        }
        return count;
    }
};