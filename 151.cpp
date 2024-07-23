#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
public:
    string reverseWords(string s){
        vector<string> words;
        words.push_back("");
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ' '){
                if (!words.back().empty()){
                    words.push_back("");
                }
            }
            else words.back() += s[i];
        }
        if (words.back().empty()) words.pop_back();
        string ans;
        for (int i = words.size() - 1; i >= 0; i--) {
            ans += words[i];
            if (i != 0) ans += " ";
        }
        return ans;
    }
};

int main() {
    Solution s;
    string str;
    getline(cin, str);
    cout << s.reverseWords(str) << endl;
    return 0;
}