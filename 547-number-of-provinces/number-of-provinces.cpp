class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), count = 0;
        vector<int> vis(n+1,0);
        queue<int> q;

        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                count++;
                q.push(i);
                vis[i] = 1;

                while(!q.empty()){
                    int x = q.front();
                    q.pop();

                    for(int j = 1; j <= n; j++){
                        if(isConnected[x-1][j-1] == 1 && !vis[j]){
                            vis[j] = 1;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return count;
    }
};