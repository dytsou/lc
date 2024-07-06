#include<iostream>

using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        return n == 1 ? 1 : time % (2 * n - 2) + 1 <= n ? time % (2 * n - 2) + 1 : 2 * n - time % (2 * n - 2) - 1;
    }
};

int main(){
    Solution s;
    int n, time;
    cin >> n >> time;
    cout << s.passThePillow(n, time) << endl;
    return 0;
}