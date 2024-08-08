#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        ans.reserve(rows * cols); // Reserve space in advance
        ans.push_back({rStart, cStart});
        
        int radius = 1, allBlocks = rows * cols;
        while(ans.size() < allBlocks) {
            // go right
            for(int i = 0; i < radius; i++) {
                cStart++;
                if (cStart >= 0 && cStart < cols && rStart >= 0 && rStart < rows)
                    ans.push_back({rStart, cStart});
            }
            // go down
            for(int i = 0; i < radius; i++) {
                rStart++;
                if (cStart >= 0 && cStart < cols && rStart >= 0 && rStart < rows)
                    ans.push_back({rStart, cStart});
            }
            radius++;
            // go left
            for(int i = 0; i < radius; i++) {
                cStart--;
                if (cStart >= 0 && cStart < cols && rStart >= 0 && rStart < rows)
                    ans.push_back({rStart, cStart});
            }
            // go up
            for(int i = 0; i < radius; i++) {
                rStart--;
                if (cStart >= 0 && cStart < cols && rStart >= 0 && rStart < rows)
                    ans.push_back({rStart, cStart});
            }
            radius++;
        }
        return ans;
    }
};

int main(){
    Solution s;
    int rows, cols, rStart, cStart;
    cin >> rows >> cols >> rStart >> cStart;
    vector<vector<int>> ans = s.spiralMatrixIII(rows, cols, rStart, cStart);
    for(auto i : ans) {
        cout << i[0] << " " << i[1] << endl;
    }
    return 0;
}
   