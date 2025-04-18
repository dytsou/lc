#include<iostream>
#include<string>
#include<algorithm>
#include<numeric>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1)? str1.substr(0, gcd(size(str1),size(str2))): "";
    }
};

int main(){
    string str1, str2;
    cin >> str1 >> str2;
    Solution s;
    cout << s.gcdOfStrings(str1, str2) << endl;
}