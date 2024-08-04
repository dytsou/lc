#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int row_ans = 0, col_ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < (m / 2); j++){
                int point = grid[i][j] + grid[i][m - j - 1];
                row_ans += point == 1;
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < (n / 2); j++){
                int point = grid[j][i] + grid[n - j - 1][i];
                col_ans += point == 1;
            }
        }
        return min(row_ans, col_ans);
    }
};