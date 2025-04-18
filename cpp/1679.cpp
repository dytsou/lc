#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
public:
    int maxOperations(vector<int>& nums, int k){
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        int ans = 0;
        while(i < j){
            if(nums[i] + nums[j] == k){
                ans++;
                i++;
                j--;
            }
            else if(nums[i] + nums[j] < k) i++;
            else j--;
        }
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i < n; i++) 
        cin >> nums[i];
    int k;
    cin >> k;
    Solution s;
    cout << s.maxOperations(nums, k) << endl;
    return 0;
}