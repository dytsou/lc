class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[i][j][cost] = maximum score at (i,j) with exactly this cost
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        
        // Starting cell
        dp[0][0][0] = 0;
        
        // Fill DP table
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int cost = 0; cost <= k; cost++) {
                    if (dp[i][j][cost] == -1) continue;
                    
                    // Move right
                    if (j + 1 < n) {
                        int cellValue = grid[i][j + 1];
                        int newCost = cost + (cellValue == 0 ? 0 : 1);
                        int newScore = dp[i][j][cost] + cellValue;
                        
                        if (newCost <= k) {
                            dp[i][j + 1][newCost] = max(dp[i][j + 1][newCost], newScore);
                        }
                    }
                    
                    // Move down
                    if (i + 1 < m) {
                        int cellValue = grid[i + 1][j];
                        int newCost = cost + (cellValue == 0 ? 0 : 1);
                        int newScore = dp[i][j][cost] + cellValue;
                        
                        if (newCost <= k) {
                            dp[i + 1][j][newCost] = max(dp[i + 1][j][newCost], newScore);
                        }
                    }
                }
            }
        }
        
        // Find maximum score at destination
        int result = -1;
        for (int cost = 0; cost <= k; cost++) {
            if (dp[m - 1][n - 1][cost] != -1) {
                result = max(result, dp[m - 1][n - 1][cost]);
            }
        }
        
        return result;
    }
};