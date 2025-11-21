class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<bool>> seen(26, vector<bool>(26, false));
        vector<int> first(26, -1);
        int count = 0;
        
        for (int i = 0; i < s.length() - 2; i++) {
            if(first[s[i] - 'a'] != -1){
                continue;
            }
            first[s[i] - 'a'] = i;
            char c = s[i];
            int firstIdx = i;
            int lastIdx = -1;
            for (int j = s.length() - 1; j > i + 1; j--) {
                if (s[j] == c) {
                    lastIdx = j;
                    break;
                }
            }
        
            if (lastIdx == -1) continue;
            
            for (int k = firstIdx + 1; k < lastIdx; k++) {
                int midChar = s[k] - 'a';
                if (!seen[c - 'a'][midChar]) {
                    seen[c - 'a'][midChar] = true;
                    count++;
                }
            }
        }
            
        return count;
    }
};