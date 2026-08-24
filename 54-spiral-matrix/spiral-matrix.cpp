class Solution {
public:
    vector<int> res;

    void spiral(vector<vector<int>>& matrix,
                int top, int bottom,
                int left, int right) {

        // Base case
        if (top > bottom || left > right)
            return;

        // 1. Top row: left -> right
        for (int i = left; i <= right; i++) {
            res.push_back(matrix[top][i]);
        }
        top++;

        // IMPORTANT: check before right column
        if (top > bottom || left > right)
            return;

        // 2. Right column: top -> bottom
        for (int i = top; i <= bottom; i++) {
            res.push_back(matrix[i][right]);
        }
        right--;

        // IMPORTANT: check before bottom row
        if (top > bottom || left > right)
            return;

        // 3. Bottom row: right -> left
        for (int i = right; i >= left; i--) {
            res.push_back(matrix[bottom][i]);
        }
        bottom--;

        // IMPORTANT: check before left column
        if (top > bottom || left > right)
            return;

        // 4. Left column: bottom -> top
        for (int i = bottom; i >= top; i--) {
            res.push_back(matrix[i][left]);
        }
        left++;

        // Recurse into the inner matrix
        spiral(matrix, top, bottom, left, right);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        spiral(matrix, 0, m - 1, 0, n - 1);

        return res;
    }
};