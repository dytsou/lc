class Solution {
public:
    long long maxOperations(string s) {
        long long result = 0;
        int ones = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '1') 
                ones++;
            else if (i > 0 && s[i - 1] == '1')
                result += ones;
        }
        return result;
    }
};