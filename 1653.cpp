#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution{
public:
    int minimumDeletions(string s) {
        int cntA = 0, cntB = 0, cnt = 0;
        cntB = (s[0] == 'b');
        cntA = count(s.begin(), s.end(), 'a');
        cnt = cntA + cntB - 1;
        for(int i=1; i<s.size(); i++){
            if(s[i] == 'b') cntB++;
            if(s[i-1] == 'a') cntA--;
            cnt = min(cnt, cntA + cntB - 1);
        }
        return cnt;
    }
};

int main(){
    Solution s;
    string str;
    cin >> str;
    cout << s.minimumDeletions(str) << endl;
    return 0;
}