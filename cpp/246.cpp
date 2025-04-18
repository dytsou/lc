#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {

        vector<long long> dp(n);
        dp[0] = 1;
        int twoPtr = 0;
        int threePtr = 0;
        int fivePtr = 0;
        long long twoMul = dp[twoPtr] * 2;
        long long threeMul = dp[threePtr] * 3;
        long long fiveMul = dp[fivePtr] * 5;

        for(int i=1;i<n;i++){
            dp[i] = min({twoMul, threeMul, fiveMul});
            if(dp[i] == twoMul)
                twoMul = dp[++twoPtr] * 2;
            if(dp[i] == threeMul)
                threeMul = dp[++threePtr] * 3;
            if(dp[i] ==  fiveMul)
                fiveMul = dp[++fivePtr] * 5;
        }
        return dp[n-1];
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    cout << s.nthUglyNumber(n) << endl;
    return 0;
}