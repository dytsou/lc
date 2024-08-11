#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x = 0, y = 0;
        for(int i = 0; i < commands.size(); i++) {
            if(commands[i] == "UP") y--;
            else if(commands[i] == "DOWN") y++;
            else if (commands[i] == "LEFT") x--;
            else if (commands[i] == "RIGHT") x++;
        }
        return y * n + x;
    }
};

int main() {
    Solution s;
    int n, commands_n;
    cin >> n >> commands_n;
    vector<string> commands(commands_n);
    for (int i = 0; i < commands_n; i++)
        cin >> commands[i];
    cout << s.finalPositionOfSnake(4, commands) << endl;
    return 0;
}