#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int maxVowels(string s, int k){
        int curr = countVowels(s.substr(0, k));
        int max_vowels = curr;
        for(int i = k; i < s.size(); i++){
            curr += isVowel(s[i]) - isVowel(s[i - k]);
            max_vowels = max(max_vowels, curr);
        }
        return max_vowels;
    }
private:
    int countVowels(string s){
        int cnt = 0;
        for(int i = 0; i < s.size(); i++)
            cnt += isVowel(s[i]);
        return cnt;
    }
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

int main(){
    string s;
    int k;
    cin >> s >> k;
    Solution s;
    cout << s.maxVowels(s, k) << endl;
    return 0;
}