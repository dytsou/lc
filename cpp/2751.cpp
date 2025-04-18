#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pair<int, int>> robots(n);
        for (int i = 0; i < n; ++i) {
            robots[i] = {positions[i], i};  // store position and index
        }
        
        // Sort robots based on positions
        sort(robots.begin(), robots.end());
        
        vector<int> stack;  // stack to store indices of robots moving to the right
        
        for (int i = 0; i < n; ++i) {
            int idx = robots[i].second;
            if (directions[idx] == 'R') {
                stack.push_back(idx);
            } else {
                while (!stack.empty()) {
                    int last = stack.back();
                    if (healths[last] > healths[idx]) {
                        healths[last] -= 1;
                        healths[idx] = -1;  // current robot is destroyed
                        break;
                    } else if (healths[last] < healths[idx]) {
                        healths[idx] -= 1;
                        healths[last] = -1;  // robot from stack is destroyed
                        stack.pop_back();
                    } else {
                        healths[idx] = -1;
                        healths[last] = -1;  // both robots are destroyed
                        stack.pop_back();
                        break;
                    }
                }
            }
        }
        
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0) result.push_back(healths[i]);
        }
        return result;
    }
};

int main(){
    Solution s;
    int n;
    cin >> n;
    vector<int> positions(n);
    vector<int> healths(n);
    string directions;
    for (int i = 0; i < n; i++)
        cin >> positions[i];
    for (int i = 0; i < n; i++)
        cin >> healths[i];
    cin >> directions;
    vector<int> res = s.survivedRobotsHealths(positions, healths, directions);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;

}