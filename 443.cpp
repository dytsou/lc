#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> charList;
        vector<int> countList;
        for(char c: chars){
            if(!charList.empty() && charList.back() == c)
                countList.back()++;
            else{
                charList.push_back(c);
                countList.push_back(1);
            }
        }
        chars.clear();
        for(int i = 0; i < charList.size(); i++){
            chars.push_back(charList[i]);
            if(countList[i] > 1){
                for(char c: to_string(countList[i]))
                    chars.push_back(c);
            }
        }
        return chars.size();
    }
};

int main(){
    int n;
    cin >> n;
    vector<char> chars(n);
    for(int i = 0; i < n; i++){
        cin >> chars[i];
    }
    Solution s;
    cout << s.compress(chars) << endl;
    return 0;
}