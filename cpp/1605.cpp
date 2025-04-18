#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                matrix[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= matrix[i][j];
                colSum[j] -= matrix[i][j];
            }
        }
        return matrix;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> rowSum(n), colSum(m);
    for(int i = 0; i < n; i++){
        cin >> rowSum[i];
    }
    for(int i = 0; i < m; i++){
        cin >> colSum[i];
    }
    Solution s;
    vector<vector<int>> res = s.restoreMatrix(rowSum, colSum);
}