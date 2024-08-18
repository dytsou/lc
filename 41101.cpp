#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans = 0;
        int n = s.length();
        for(int i = 1; i <= n; i++){
            int zeros = 0, ones = 0;
            for(int j = 0; j < i; j++){
                if(s[j] == '0') zeros++;
                else ones++;
            }
            if(zeros <= k || ones <= k) ans++;
            for(int j = 0; j < n - i; j++){
                zeros += (s[j + i] == '0') - (s[j] == '0');
                ones += (s[j + i] == '1') - (s[j] == '1');
                if(zeros <= k || ones <= k) ans++;
            }
        }
        return ans;
    }
};