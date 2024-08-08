#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> full(2001, 0);
        for(int i : nums1) 
            if(full[i+1000] != 1) full[i+1000]++;
        for(int i : nums2) 
            if(full[i+1000] != 2) full[i+1000] += 2;
        vector<vector<int>> ans(2);
        for(int i=0; i<2001; i++){
            if(full[i] == 1) ans[0].push_back(i-1000);
            else if(full[i] == 2) ans[1].push_back(i-1000);
        }
        return ans;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n), nums2(m);
    for(int i=0; i<n; i++) 
        cin >> nums1[i];
    for(int i=0; i<m; i++) 
        cin >> nums2[i];
    Solution s;
    vector<vector<int>> ans = s.findDifference(nums1, nums2);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}