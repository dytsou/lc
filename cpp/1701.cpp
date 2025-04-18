#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int time = 0;
        double wait = 0;
        int n = customers.size();
        for (int i = 0; i < n; i++) {
            time = max(time, customers[i][0]) + customers[i][1];
            wait += time - customers[i][0];
        }
        return wait / n;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<vector<int>> customers(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> customers[i][0] >> customers[i][1];
    }
    cout << sol.averageWaitingTime(customers) << endl;
    return 0;
}