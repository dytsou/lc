#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        for(char c : s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        }
        return false;
    }
};

int main(){
    Solution s;
    string str;
    cin >> str;
    cout << s.doesAliceWin(str) << endl;
}