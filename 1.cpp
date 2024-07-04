#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(map.find(target-nums[i]) != map.end()){
                ans.push_back(map[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            map[nums[i]] = i;
        }
        return ans;
    }
};



int main(){
    Solution s;
    int n;
    cin >> n;
    vector<int> nums(n);
    int target;
    for(int i=0; i<n; i++)
        cin >> nums[i];
    cin >> target;
    vector<int> ans = s.twoSum(nums, target);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}