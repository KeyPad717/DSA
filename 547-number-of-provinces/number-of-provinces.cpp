class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0, n=isConnected.size();
        vector<int> res,vis(n+1,0);
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                count++;
                vis[i]=1;
                q.push(i);
                while(!q.empty()){
                    int x=q.front();
                    q.pop();
                    for(int j=1;j<=n;j++){
                        if((x-1)!=(j-1)){
                            if(isConnected[x-1][j-1]==1){
                                if(vis[j]==0){
                                    q.push(j);
                                    vis[j]=1;
                                }
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};