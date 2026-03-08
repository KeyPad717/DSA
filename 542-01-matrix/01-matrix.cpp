#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        // Use a large value that won't overflow when adding 1
        const int INF = INT_MAX / 4;

        // Initialize: 1 -> INF, 0 -> 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) mat[i][j] = INF;
            }
        }

        // Pass 1: top-left to bottom-right (use top and left)
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) continue;
                if (i > 0) mat[i][j] = min(mat[i][j], mat[i-1][j] + 1);
                if (j > 0) mat[i][j] = min(mat[i][j], mat[i][j-1] + 1);
            }
        }

        // Pass 2: bottom-right to top-left (use bottom and right)
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (mat[i][j] == 0) continue;
                if (i + 1 < m) mat[i][j] = min(mat[i][j], mat[i+1][j] + 1);
                if (j + 1 < n) mat[i][j] = min(mat[i][j], mat[i][j+1] + 1);
            }
        }

        return mat;
    }
};
