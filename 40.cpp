#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results = {};
        vector<int> result = {};
        sort(candidates.begin(), candidates.end());
        sumUtil(target, 0, result, candidates, results);
        return results;
    }
private:
    void sumUtil(int target, int currIdx, vector<int>& result, vector<int>& candidates, vector<vector<int>>& results){
        if(target == 0){
            results.push_back(result);
            return;
        }
        if(target < 0) 
            return;
        for(int i = currIdx; i < candidates.size(); i++){
            if(i != currIdx && candidates[i] == candidates[i-1])
                continue;
            result.push_back(candidates[i]);
            sumUtil(target - candidates[i], i + 1, result, candidates, results);
            result.pop_back();
        }
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> candidates(n);
    for(int i = 0; i < n; i++)
        cin >> candidates[i];
    int target;
    cin >> target;
    Solution s;
    vector<vector<int>> res = s.combinationSum2(candidates, target);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}