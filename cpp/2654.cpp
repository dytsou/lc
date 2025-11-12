class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for(int num : nums) {
            if(num == 1) ones++;
        }
        if(ones > 0) return n - ones;
        
        // Find minimum length subarray with gcd = 1
        int minLen = INT_MAX;
        for(int i = 0; i < n; i++) {
            int g = nums[i];
            for(int j = i + 1; j < n; j++) {
                g = gcd(g, nums[j]);
                if(g == 1) {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }
        
        // If no subarray with gcd = 1 exists, return -1
        if(minLen == INT_MAX) return -1;
        
        // minLen - 1 operations to create a 1, then n - 1 operations to spread it
        return minLen - 1 + n - 1;
    }
};