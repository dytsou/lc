#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        dp.resize(n, vector<int>(n, -1));
        return flips(s, 0, n - 1);
    }
private:
    vector<vector<int>> dp;
    int flips(string& s, int l, int r){
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int i = l;
        while(i + 1 <= r && s[i] == s[i + 1]) i++;
        int res = 1 + flips(s, i + 1, r); 
        for(int j = i + 1; j <= r; j++){
            if(s[j] == s[l])
                res = min(res, flips(s, j, r) + flips(s, i + 1, j - 1));
        }
        return dp[l][r] = res;
    }
};

int main(){
    Solution s;
    string str;
    cin >> str;
    cout << s.strangePrinter(str) << endl;
    return 0;
}