#include<iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int mask = 1;
        while(mask < num)
            mask = (mask << 1) | 1;
        return num ^ mask;
    }
};

int main(){
    Solution s;
    int num;
    cin >> num;
    cout << s.findComplement(num) << endl;
    return 0;
}