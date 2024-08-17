#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m, 0));
        for(int i = 0; i < m; i++)
            dp[0][i] = points[0][i];

        for(int i = 1; i < n; i++){
            vector<long long> left(m, 0), right(m, 0);
            left[0] = dp[i - 1][0];
            for(int j = 1; j < m; j++)
                left[j] = max(left[j - 1] - 1, dp[i - 1][j]);
            right[m - 1] = dp[i - 1][m - 1];
            for(int j = m - 2; j >= 0; j--)
                right[j] = max(right[j + 1] - 1, dp[i - 1][j]);
            for(int j = 0; j < m; j++)
                dp[i][j] = max(left[j], right[j]) + points[i][j];
        }
        long long res = 0;
        for(int i = 0; i < m; i++)
            res = max(res, (long long)dp.back()[i]);
        return res;
    }
};

int main() {
    Solution s;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> points(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> points[i][j];
    }
    cout << s.maxPoints(points) << endl;
    return 0;
}