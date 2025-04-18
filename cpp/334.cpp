#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX, b = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= a)
                a = nums[i];
            else if(nums[i] <= b)
                b = nums[i];
            else 
                return true;
        }
        return false;
    }
};

int main(){
    Solution sol;
    int n;
    cin >> n;
    vector<int> nums(n);
    cout << sol.increasingTriplet(nums) << endl;
    return 0;
}