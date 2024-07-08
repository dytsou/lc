#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v(n);
        for(int i=0; i<n; i++) v[i] = i+1;
        int idx = 0;
        while(v.size() > 1){
            idx = (idx + k-1) % v.size();
            v.erase(v.begin() + idx);
        }
        return v[0];
    }
};

int main(){
    Solution s;
    int n, k;
    cin >> n >> k;
    cout << s.findTheWinner(n, k) << endl;
    return 0;
}