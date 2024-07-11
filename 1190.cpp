#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        stack<int> last_para;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')
                last_para.push(ans.size());
            else if(s[i] == ')'){
                int loc = last_para.top();
                last_para.pop();
                reverse(ans.begin() + loc, ans.end());
            }
            else
                ans.push_back(s[i]);   
        }
        return ans;
    }
};

int main(){
    Solution s;
    string str;
    cin >> str;
    cout << s.reverseParentheses(str) << endl;
    return 0;
}