#include<iostream>
#include<vector>

using namespace std;

class neighborSum {
public:
    neighborSum(vector<vector<int>>& grid) {
        this->grid = grid;
    }
    
    int adjacentSum(int value) {
        pair<int, int> pos = findValue(value);
        int x = pos.first;
        int y = pos.second;
        int sum = 0;
        if(x > 0) sum += grid[x-1][y];
        if(x < grid.size()-1) sum += grid[x+1][y];
        if(y > 0) sum += grid[x][y-1];
        if(y < grid[x].size()-1) sum += grid[x][y+1];
        return sum;
    }
    
    int diagonalSum(int value) {
        pair<int, int> pos = findValue(value);
        int x = pos.first;
        int y = pos.second;
        int sum = 0;
        if(x > 0 && y > 0) sum += grid[x-1][y-1];
        if(x > 0 && y < grid[x].size()-1) sum += grid[x-1][y+1];
        if(x < grid.size()-1 && y > 0) sum += grid[x+1][y-1];
        if(x < grid.size()-1 && y < grid[x].size()-1) sum += grid[x+1][y+1];
        return sum;
    }
private:
    vector<vector<int>> grid;
    pair<int, int> findValue(int value) {
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == value) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};