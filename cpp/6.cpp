#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> vec(numRows, "");
        int idx = 0, flag = -1;
        for(int i = 0; i < s.size(); i++){
            vec[idx] += s[i];
            if(idx == 0 || idx == numRows - 1) flag = -flag;
            idx += flag;
        }
        string ans;
        for(auto str: vec){
            ans += str;
        }
        return ans;
    }
};

int main(){
    Solution s;
    string str;
    int numRows;
    cin >> str >> numRows;
    cout << s.convert(str, numRows) << endl;
    return 0;
}
