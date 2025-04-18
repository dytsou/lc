#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr = 0, highest =0;
        for(int i : gain){
            curr += i;
            highest = max(highest, curr);
        }
        return highest;
    }
};

int main(){
    Solution s;
    int n;
    cin >> n;
    vector<int> gain(n);
    cout << s.largestAltitude(gain) << endl;
    return 0;
}