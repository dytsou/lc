class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        // dp[i][j][r] = number of paths to (i, j) with sum % k == r
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));

        int firstRem = grid[0][0] % k;
        dp[0][0][firstRem] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                int valRem = grid[i][j] % k;

                // from top
                if (i > 0) {
                    for (int r = 0; r < k; r++) {
                        if (dp[i - 1][j][r] == 0) continue;
                        int newRem = (r + valRem) % k;
                        dp[i][j][newRem] = (dp[i][j][newRem] + dp[i - 1][j][r]) % MOD;
                    }
                }

                // from left
                if (j > 0) {
                    for (int r = 0; r < k; r++) {
                        if (dp[i][j - 1][r] == 0) continue;
                        int newRem = (r + valRem) % k;
                        dp[i][j][newRem] = (dp[i][j][newRem] + dp[i][j - 1][r]) % MOD;
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0]; // return the number of paths to the bottom-right cell with sum % k == 0
    }
private:
    static const int MOD = 1e9 + 7;
};