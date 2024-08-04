#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> picked_balls(n, vector<int>(11, 0));
        for(int i = 0; i < pick.size(); i++){
            int x = pick[i][0];
            int y = pick[i][1];
            picked_balls[x][y]++;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 11; j++){
                if(picked_balls[i][j] > i){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};