#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k == 1) return nums;
        int n = nums.size();
        vector<int> asc;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] == nums[i + 1] - 1) asc.push_back(1);
            else asc.push_back(0);
        }
        vector<int> ans;
        int sum = 0, i = 0;
        for(; i < k - 1; i++) sum += asc[i];
        for(; i < n - 1; i++){
            if(sum == k - 1) ans.push_back(nums[i]);
            else ans.push_back(-1);
            sum += asc[i] - asc[i - k + 1];
        }
        if(sum == k - 1) ans.push_back(nums[i]);
        else ans.push_back(-1);
        return ans;
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
    vector<int> ans = s.resultsArray(nums, k);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
