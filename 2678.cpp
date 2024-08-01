#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(int i=0; i<details.size(); i++){
            if(details[i][11] > '6' || (details[i][11] == '6' && details[i][12] > '0'))
                ans++;
        }
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<string> details(n);
    for(int i=0; i<n; i++)
        cin >> details[i];
    Solution s;
    cout << s.countSeniors(details) << endl;
}