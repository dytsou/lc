#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int curr = 0;
        for(int i = 0; i < k; i++)
            curr += nums[i];
        int currMax = curr;
        for(int i = 1; i <= n - k; i++){
            curr += nums[i + k - 1] - nums[i - 1];
            currMax = max(currMax, curr);
        }
        return (double)currMax / k;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    int k;
    cin >> k;
    Solution s;
    cout << s.findMaxAverage(nums, k) << endl;
    return 0;
}