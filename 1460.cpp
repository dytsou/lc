#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target.size() != arr.size()) return false;
        int max_target = *max_element(target.begin(), target.end());
        int max_arr = *max_element(arr.begin(), arr.end());
        if(max_target != max_arr) return false;
        vector<int> cnt(max_target + 1, 0);
        for(int i = 0; i < target.size(); i++){
            cnt[target[i]]++;
            cnt[arr[i]]--;
        }
        for(int i = 0; i < cnt.size(); i++)
            if(cnt[i] != 0) return false;
        return true;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> target(n), arr(m);
    for(int i = 0; i < n; i++)
        cin >> target[i];
    for(int i = 0; i < m; i++)
        cin >> arr[i];
    Solution s;
    cout << s.canBeEqual(target, arr) << endl;
    return 0;
}