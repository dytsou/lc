#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        graph.resize(n * 3, vector<int>(n * 3, 0));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '/') diagonalSeparate(i, j);
                else if(grid[i][j] == '\\') antiDiagonalSeparate(i, j);
            }
        }
        for(int i = 0; i < graph.size(); i++){
            for(int j = 0; j < graph[0].size(); j++){
                if(graph[i][j] == 0){
                    dfs(i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
private:
    vector<vector<int>> graph;
    void diagonalSeparate(int i, int j){
        graph[i * 3][j * 3 + 2] = 1;
        graph[i * 3 + 1][j * 3 + 1] = 1;
        graph[i * 3 + 2][j * 3] = 1;
    }
    void antiDiagonalSeparate(int i, int j){
        graph[i * 3][j * 3] = 1;
        graph[i * 3 + 1][j * 3 + 1] = 1;
        graph[i * 3 + 2][j * 3 + 2] = 1;
    }
    void dfs(int i, int j){
        if(i < 0 || i >= graph.size() || j < 0 || j >= graph.size() || graph[i][j] == 1) return;
        graph[i][j] = 1;
        dfs(i - 1, j);
        dfs(i + 1, j);
        dfs(i, j - 1);
        dfs(i, j + 1);
    }
};

int main(){
    vector<string> grid = {" /", "/ "};
    Solution s;
    cout << s.regionsBySlashes(grid) << endl;
    return 0;
}
