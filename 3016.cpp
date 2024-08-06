#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> alphabets(26);
        for(char c : word) alphabets[c - 'a']++;
        int cnt = 0, ans = 0;
        sort(alphabets.rbegin(), alphabets.rend());
        for(int i : alphabets){
            if(i == 0) break;
            ans += i * ((cnt++ / 8) + 1);
        }
        return ans;
    }
};

int main(){
    string str;
    cin >> str;
    Solution s;
    cout << s.minimumPushes(str) << endl;
    return 0;
}