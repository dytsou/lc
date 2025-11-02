    class Solution {
    public:
        int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
            vector<vector<unsigned char>> grid(m, vector<unsigned char>(n, 0));

            for (const auto& w : walls) grid[w[0]][w[1]] = WALL;
            for (const auto& g : guards) grid[g[0]][g[1]] = GUARD;
            // scan rows
            for (int i = 0; i < m; i++) {
                bool seen = false;
                for (int j = 0; j < n; j++) 
                    markGuardArea(grid, i, j, seen); // left to right
                seen = false;
                for (int j = n - 1; j >= 0; j--) 
                    markGuardArea(grid, i, j, seen); // right to left
            }

            // scan columns
            for (int j = 0; j < n; j++) {
                bool seen = false;
                for (int i = 0; i < m; i++)
                    markGuardArea(grid, i, j, seen); // top to bottom
                seen = false;
                for (int i = m - 1; i >= 0; i--)
                    markGuardArea(grid, i, j, seen); // bottom to top
            }

            int ans = 0;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    if (grid[i][j] == EMPTY) ans++;
            return ans;
        }
        private:
        static const int WALL = 3;
        static const int GUARD = 2;
        static const int GUARDED = 1;
        static const int EMPTY = 0;

        void markGuardArea(vector<vector<unsigned char>>& grid, int i, int j, bool &seen) {
          if (grid[i][j] == WALL || grid[i][j] == GUARD) {
            seen = false;
          } else {
            if (seen && grid[i][j] == EMPTY) grid[i][j] = GUARDED;
          }
          if (grid[i][j] == GUARD) seen = true;
        }
    };
