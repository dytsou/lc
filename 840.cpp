#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        for(int i = 0; i < row - 2; i++){
            for(int j = 0; j < col - 2; j++){
                if(findMagicSquare(grid, i, j))
                    count++;
            }
        }
        return count;
    }
private:
    bool findMagicSquare(vector<vector<int>>& grid, int i, int j){
        // exist 1-9
        vector<int> nums(10, 0);
        for(int x = i; x < i + 3; x++){
            for(int y = j; y < j + 3; y++){
                if(grid[x][y] < 1 || grid[x][y] > 9) return false;
                nums[grid[x][y]]++;
            }
        }
        for(int k = 1; k <= 9; k++){
            if(nums[k] != 1) return false;
        }
        // sum
        int sum = 15;
        // row sum
        for(int y = j; y < j + 3; y++){
            int temp = 0;
            for(int x = i; x < i + 3; x++)
                temp += grid[x][y];
            if(temp != sum) return false;
        }
        // col sum
        for(int x = i + 1; x < i + 3; x++){
            int temp = 0;
            for(int y = j; y < j + 3; y++)
                temp += grid[x][y];
            if(temp != sum) return false;
        }
        // diagonal sum
        if(grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != sum)
            return false;
        // anti-diagonal sum
        if(grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] != sum)
            return false;
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