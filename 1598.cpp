#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int d = 0;
        for(string log : logs){
            d = log == "../" && d == 0 ? 0 : log == "../" ? --d : log != "./" ? ++d : d;
        }
        return d;
    }
};

int main(){
    Solution s;
    int n;
    cin >> n;
    vector<string> logs(n);
    for (int i = 0; i < n; i++) {
        cin >> logs[i];
    }
    cout << s.minOperations(logs) << endl;
    return 0;

}