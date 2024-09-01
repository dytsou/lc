#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m * n)
            return {};
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                ans[i][j] = original[i * n + j];
        return ans;
    }
};

int main(){
    int len, m, n;
    cin >> len;
    vector<int> original(len);
    for(int i=0; i<len; i++)
        cin >> original[i];
    cin >> m >> n;
    Solution s;
    vector<vector<int>> ans = s.construct2DArray(original, m, n);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}