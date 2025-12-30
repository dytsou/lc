#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int result = 0;

        for (int i = 1; i + 1 < n; i++) {
            for (int j = 1; j + 1 < m; j++) {
                if (grid[i][j] == 5 && checkMagicSquare(grid, i, j))
                    ++result;
            }
        }
        return result;
    }

private:
    static bool isEven(int x) { return (x & 1) == 0; }
    static bool sumOfTen(int a, int b) { return a + b == 10; }

    bool checkMagicSquare(const vector<vector<int>>& g, int i, int j) {
        int n = g.size(), m = g[0].size();
        if (i - 1 < 0 || i + 1 >= n || j - 1 < 0 || j + 1 >= m) return false;

        bool seen[10] = {false};
        for (int r = i - 1; r <= i + 1; ++r) {
            for (int c = j - 1; c <= j + 1; ++c) {
                int x = g[r][c];
                if (x < 1 || x > 9) return false;
                if (seen[x]) return false;
                seen[x] = true;
            }
        }

        if (!isEven(g[i - 1][j - 1]) || !isEven(g[i + 1][j - 1]) ||
            !isEven(g[i - 1][j + 1]) || !isEven(g[i + 1][j + 1])) return false;

        if (isEven(g[i][j - 1]) || isEven(g[i - 1][j]) ||
            isEven(g[i][j + 1]) || isEven(g[i + 1][j])) return false;

        if (!sumOfTen(g[i][j - 1], g[i][j + 1]) ||
            !sumOfTen(g[i - 1][j], g[i + 1][j]) ||
            !sumOfTen(g[i - 1][j - 1], g[i + 1][j + 1]) ||
            !sumOfTen(g[i + 1][j - 1], g[i - 1][j + 1])) return false;

        int s0 = g[i - 1][j - 1] + g[i - 1][j] + g[i - 1][j + 1];
        int s1 = g[i][j - 1]     + g[i][j]     + g[i][j + 1];
        int s2 = g[i + 1][j - 1] + g[i + 1][j] + g[i + 1][j + 1];
        if (!(s0 == s1 && s1 == s2)) return false;

        int c0 = g[i - 1][j - 1] + g[i][j - 1] + g[i + 1][j - 1];
        int c1 = g[i - 1][j]     + g[i][j]     + g[i + 1][j];
        int c2 = g[i - 1][j + 1] + g[i][j + 1] + g[i + 1][j + 1];
        if (!(c0 == c1 && c1 == c2)) return false;

        int d0 = g[i - 1][j - 1] + g[i][j] + g[i + 1][j + 1];
        int d1 = g[i - 1][j + 1] + g[i][j] + g[i + 1][j - 1];
        if (d0 != d1) return false;

        return true;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    Solution s;
    cout << s.numMagicSquaresInside(grid) << endl;
    return 0;
}