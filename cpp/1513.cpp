class Solution {
public:
    int numSub(string s) {
        bool flag = false;
        long long result = 0, oneStart = 0, n = s.size();
        long long mod = 1e9 + 7;
        for (long long i = 0; i < n; i++){
            char c = s[i];
            if (flag && c == '0'){
                long long cnt = i - oneStart;
                result += (cnt + 1) * cnt / 2;
                flag = false;
            } else if (!flag && c == '1'){
                flag = true;
                oneStart = i;
            }
        }
        if(flag){
            long long cnt = n - oneStart;
            result += (cnt + 1) * cnt / 2;
        }
        return (int)(result % mod);
    }
};