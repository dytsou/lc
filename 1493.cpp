#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size(), k = 1;
        while(j < n){
            if(nums[j] == 0) k--;
            if(k < 0 && nums[i++] == 0) k++;
            j++;
        }
        return j - i - 1;
    }
};

int main(){
    Solution s;
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) 
        cin >> nums[i];
    cout << s.longestSubarray(nums) << endl;
    return 0;
}