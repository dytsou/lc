#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minDays(vector<vector<int>>& grid){
        n = grid.size();
        m = grid[0].size();
        if(countIslands(grid) != 1) // more than 1 island
            return 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0; // remove the island
                    if(countIslands(grid) != 1) // more than 1 island
                        return 1;
                    grid[i][j] = 1; // restore the island
                }
            }
        }
        // we can't remove any single island to make it disconnected
        return 2; // we can isolate an island by removing 2 of its adjacent islands
    }
private:
    int m, n;
    int countIslands(vector<vector<int>>& grid){
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2) grid[i][j] = 1;
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 1) return;
        grid[i][j] = 2;
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    Solution s;
    cout << s.minDays(grid) << endl;
    return 0;
}