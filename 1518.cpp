#include <iostream>

using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while(numBottles / numExchange){
            ans += numBottles / numExchange;
            numBottles = (numBottles / numExchange) + (numBottles % numExchange);
        }
        return ans;
    }
};

int main() {
    Solution s;
    int numBottles, numExchange;
    cin >> numBottles >> numExchange;
    cout << s.numWaterBottles(numBottles, numExchange) << endl;
    return 0;
}