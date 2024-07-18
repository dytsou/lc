#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int n = min(word1.size(), word2.size());
        for(int i = 0; i < n; i++){
            ans += word1[i];
            ans += word2[i];
        }
        return ans + word1.substr(n) + word2.substr(n);
    }
};

int main(){
    string a, b;
    cin >> a >> b;
    Solution s;
    cout << s.mergeAlternately(a, b) << endl;
}