#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        char *p = &s[0], *q = &t[0];
        while(p != &s[s.size()] && q != &t[t.size()]){
            if(*p == *q) p++;
            q++;
        }
        return p == &s[s.size()];
    }
};

int main() {
    Solution sol;
    string s, t;
    cin >> s >> t;
    cout << sol.isSubsequence(s, t) << endl;
    return 0;
}