#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singleDigit = 0;
        int doubleDigit = 0;
        for(int i : nums){
            if(i < 10 || i == 100) singleDigit += i;
            else doubleDigit += i;
        }
        return !(singleDigit == doubleDigit);
    }
};

int main(){
    Solution s;
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i < n; i++){
        cin >> nums[i];
    }
    cout << s.canAliceWin(nums) << endl;
    return 0;
}
