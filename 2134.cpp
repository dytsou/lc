#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones = count(nums.begin(), nums.end(), 1);
        int n = nums.size();
        if(ones == 0 || ones == n) return 0;
        vector<int> windows(n, 0);
        windows[0] = count(nums.begin(), nums.begin() + ones, 1); 
        nums.insert(nums.end(), nums.begin(), nums.end());
        int cnt = windows[0];
        for(int i = 1; i < n; i++){
            windows[i] = windows[i - 1] - nums[i - 1] + nums[i + ones - 1];
            cnt = max(cnt, windows[i]);
        }
        return ones - cnt;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    Solution s;
    cout << s.minSwaps(nums) << endl;
    return 0;
}