#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0, rightSum = 0;
        for(int i = 0; i < nums.size(); i++)
            rightSum += nums[i];
        for(int i = 0; i < nums.size(); i++){
            rightSum -= nums[i];
            if(leftSum == rightSum) return i;
            leftSum += nums[i];
        }
        return -1;
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    cout << s.pivotIndex(nums) << endl;
    return 0;
}