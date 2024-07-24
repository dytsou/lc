#include<iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while(x){
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return (ans < INT_MIN || ans > INT_MAX) ? 0 : ans;
    }
};

int main(){
    Solution s;
    int x;
    cin >> x;
    cout << s.reverse(x) << endl;
    return 0;
}