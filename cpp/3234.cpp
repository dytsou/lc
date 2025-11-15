class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> onesAtZeroPositions = {0};
        int counts[2] = {0, 0};
        int result = 0;
        
        for (const char c : s) {
            counts[c - '0']++;
            if (c == '0') onesAtZeroPositions.push_back(counts[1]);
            
            result += counts[1] - onesAtZeroPositions[counts[0]];
            for (int i = counts[0] - 1; i >= 0; i--) {
                const int numZeros = counts[0] - i;
                
                if (numZeros * numZeros > counts[1]) break;

                const int highOnes = counts[1] - onesAtZeroPositions[i];
                const int lowOnes = counts[1] - onesAtZeroPositions[i + 1];
                
                if (highOnes < numZeros * numZeros) continue;
                
                const int threshold = numZeros * numZeros;
                const int validRange = highOnes - max(lowOnes, threshold) + 1;
                result += max(0, validRange);
            }
        }
        
        return result;
    }
};