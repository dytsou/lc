#include<iostream>

using namespace std;

class Solution {
public:
    int minChanges(int n, int k) {
        int a = n&k;
        int b = n|k;
        if (b != n || a != k) return -1;
        int cnt = 0;
        while (n) {
            if (n&1 && !(k&1)){
                cnt++;
            }
            n >>= 1;
            if (k) k >>= 1;
        }
        return cnt;
    }
};

int main(){
    int n, k;
    cin >> n >> k;
    Solution s;
    cout << s.minChanges(n, k) << endl;
}