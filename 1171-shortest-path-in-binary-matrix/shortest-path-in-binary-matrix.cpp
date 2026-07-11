class Solution {
public:
    const int dr[8] = {0, 0, 1, -1, 1, -1, 1, -1};
    const int dc[8] = {1, -1, 0, 0, 1, -1, -1, 1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)   return -1;
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(n, 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    vis[i][j] = 0;
            }
        }
        q.push({{0, 0}, 0});
        vis[0][0]=1;
        while (!q.empty()) {
            int c1 = q.front().first.first;
            int c2 = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            if (c1 == n - 1 && c2 == n - 1) {
                // for (int i = 0; i < n; i++) {
                //     for (int j = 0; j < n; j++) {
                //         cout<<vis[i][j]<<" ";
                //     }
                //     cout<<endl;
                // }
                return dist + 1;
            }
            for (int i = 0; i < 8; i++) {
                int x = c1 + dr[i];
                int y = c2 + dc[i];
                
                if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 0 &&
                    vis[x][y] == 0) {
                        //cout<<x<<" "<<y<<endl;
                    q.push({{x, y}, dist + 1});
                    vis[x][y]=1;
                }
            }
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout<<vis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return -1;
    }
};