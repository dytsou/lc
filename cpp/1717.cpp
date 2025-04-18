# include <iostream>
# include <string>

using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int a_count = 0;
        int b_count = 0;
        int less_point = min(x, y);
        int result = 0;
        for(char c : s){
            if(c > 'b'){
                result += min(a_count, b_count) * less_point;
                a_count = 0;
                b_count = 0;
            }
            else if(c == 'a'){
                if(x < y && b_count > 0){
                    b_count--;
                    result += y;
                }
                else a_count++;
            }
            else if(c == 'b'){
                if(y < x && a_count > 0){
                    a_count--;
                    result += x;
                }
                else b_count++;
            }
        }
        result += min(a_count, b_count) * less_point;
        return result;
    }
};

int main(){
    Solution s;
    string str;
    int x, y;
    cin >> str >> x >> y;
    cout << s.maximumGain(str, x, y) << endl;
    return 0;
}