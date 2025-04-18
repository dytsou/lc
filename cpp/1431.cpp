#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = 0;
        vector<bool> ans(candies.size(), false);
        for(int i = 0; i < candies.size(); i++)
            maxCandies = max(maxCandies, candies[i]);
        for(int i = 0; i < candies.size(); i++)
            ans[i] = candies[i] + extraCandies >= maxCandies;
        return ans;
    }
};

int main(){
    int n, extraCandies;
    cin >> n >> extraCandies;
    vector<int> candies(n);
    for(int i = 0; i < n; i++){
        cin >> candies[i];
    }
    Solution s;
    vector<bool> ans = s.kidsWithCandies(candies, extraCandies);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}