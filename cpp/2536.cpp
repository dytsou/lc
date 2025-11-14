class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        // Step 1: Initialize
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        // Step 2: Mark corners for 2D difference
        for (const auto& q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            matrix[r1][c1] += 1;
            if (r2 + 1 < n) matrix[r2 + 1][c1] -= 1;
            if (c2 + 1 < n) matrix[r1][c2 + 1] -= 1;
            if (r2 + 1 < n && c2 + 1 < n) matrix[r2 + 1][c2 + 1] += 1;
        }
        // Step 3: 2D prefix sum restoration
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) matrix[i][j] += matrix[i-1][j];
                if (j > 0) matrix[i][j] += matrix[i][j-1];
                if (i > 0 && j > 0) matrix[i][j] -= matrix[i-1][j-1];
            }
        }
        return matrix;
    }
};

