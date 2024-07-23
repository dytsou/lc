#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int i : nums)
            freq[i]++;
        sort(nums.begin(), nums.end(), [&](int a, int b){
            return freq[a] == freq[b] ? a > b : freq[a] < freq[b];
        });
        return nums;
    }
};

int main(){
    Solution s;
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin >> nums[i];
    vector<int> ans = s.frequencySort(nums);
    for(int i : ans) 
        cout << i << " ";
    cout << endl;
    return 0;
 
}