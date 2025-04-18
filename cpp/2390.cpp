#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string ans;
        for(char c : s){
            if(c == '*'){
                if(!ans.empty()) ans.pop_back();
            }
            else ans += c;
        }
        return ans;
    }
};

int main() {
    Solution s;
    string str;
    cin >> str;
    cout << s.removeStars(str) << endl;
    return 0;
}