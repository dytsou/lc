class Solution {
public:
    vector<string> generateParenthesis(int n) {
        dp.assign(n + 1, {});
        dp[0] = {""}; // n = 0, only one empty string
        for (int i = 1; i <= n; i++) {
            vector<string> current; // current combination of parentheses
            for (int j = 0; j < i; j++) {
                for (string& left : dp[j]) {
                    for (string& right : dp[i - 1 - j]) {
                        current.push_back("(" + left + ")" + right);
                    }
                }
            }
            dp[i] = current; // update the dp array
        }
        return dp[n];
    }
private:
    vector<vector<string>> dp;
};