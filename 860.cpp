#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;
        for(int i = 0; i < bills.size(); i++) {
            if(bills[i] == 5) fives++;
            else if(bills[i] == 10){
                tens++;
                fives--;
            } 
            else if(tens > 0){
                tens--;
                fives--;
            }
            else fives -= 3;
            if(fives < 0) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    vector<int> bills(n);
    for(int i = 0; i < n; i++) 
        cin >> bills[i];
    cout << s.lemonadeChange(bills) << endl;
    return 0;
}