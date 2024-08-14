#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front();
        while(left < right){
            int mid = left + (right - left) / 2;
            int cnt = 0, start = 0;
            for(int i = 0; i < nums.size(); i++){
                while(start < nums.size() && nums[i] - nums[start] > mid)
                    start++; // if diff is too large, move start to decrease diff
                cnt += i - start; // count the number of pairs with diff <= mid
            }
            if(cnt < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int k;
    cin >> k;
    cout << s.smallestDistancePair(nums, k) << endl;
    return 0;
}