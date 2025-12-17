class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0)
            return 0;
        int col = matrix[0].size();
        int best = 0;
        vector<int> height(col, 0);

        for (int r1 = 0; r1 < row; r1++) {
            fill(height.begin(), height.end(), 0);
            for (int r2 = r1; r2 < row; r2++) {
                for (int c = 0; c < col; c++) {
                    if (matrix[r2][c] == '1')
                        height[c]++;
                    else
                        height[c] = 0;
                }
                best = max(best, largestRectangleArea(height));
            }
        }
        return best;
    }

private:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int area = 0, n = heights.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                area = max(area, h * width);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? n : n - st.top() - 1;
            area = max(area, h * width);
        }
        return area;
    }
};
// The algorithm treats each row as the base of a histogram.
// For every starting row, it builds heights of consecutive 1s column by column and computes the largest rectangle that can fit in that histogram.
// By repeating this for all row ranges, it finds the maximum rectangle of 1s in the whole matrix.