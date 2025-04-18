#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.resize(n, vector<int>(n, 0));
        sum.resize(n, 0);
        sum[n - 1] = piles[n - 1];
        for(int i = n - 2; i >= 0; i--)
            sum[i] = sum[i + 1] + piles[i];
        return dfs(piles, 0, 1);  
    }
private:
    vector<vector<int>> dp;
    vector<int> sum;
    int dfs(vector<int>& piles, int i, int m){
        if(i == piles.size())
            return 0;
        if(2 * m >= piles.size() - i)
            return sum[i];
        if(dp[i][m] != 0)
            return dp[i][m];
        int res = 0;
        for(int x = 1; x <= 2 * m && i + x <= piles.size(); x++)
            res = max(res, sum[i] - dfs(piles, i + x, max(m, x)));
        return dp[i][m] = res;
    }
};

int main(){
    Solution s;
    int n;
    cin >> n;
    vector<int> piles(n);
    for(int i = 0; i < n; i++)
        cin >> piles[i];
    cout << s.stoneGameII(piles) << endl
    return 0;
}