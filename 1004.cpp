#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size();
        while(j < n){
            if(nums[j] == 0) k--;
            if(k < 0)
                if(nums[i++] == 0) k++;
            j++;
        }
        return j - i;
    }
};

int main(){
    Solution s;
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    int k;
    cin >> k;
    cout << s.longestOnes(nums, k) << endl;
    return 0;
}