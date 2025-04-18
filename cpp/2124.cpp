#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool checkString(string s) {
        bool existB = false;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'b') existB = true;
            else if(existB) return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    string str;
    cin >> str;
    cout << s.checkString(str) << endl;
    return 0;
}