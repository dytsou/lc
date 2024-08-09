#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        unordered_map<int, int> mp2;
        for(int i = 0; i < arr.size(); i++)
            mp[arr[i]]++;
        for(auto it = mp.begin(); it != mp.end(); it++)
            mp2[it->second]++;
        for(auto it = mp2.begin(); it != mp2.end(); it++)
            if(it->second > 1)
                return false;
        return true;
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << s.uniqueOccurrences(arr) << endl;
    return 0;
}