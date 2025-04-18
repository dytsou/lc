#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        for(int i=0; i<matrix.size(); i++){
            int min = matrix[i][0], idx = 0;
            for(int j=1; j<matrix[i].size(); j++){
                if(matrix[i][j] < min){
                    min = matrix[i][j];
                    idx = j;
                }
            }
            bool flag = true;
            for(int k=0; k<matrix.size(); k++){
                if(matrix[k][idx] > min){
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(min);
        }
        return ans;
    }
};

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }
    Solution s;
    vector<int> ans = s.luckyNumbers(matrix);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}