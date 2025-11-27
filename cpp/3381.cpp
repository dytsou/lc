class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Track minimum prefix sum for each length remainder mod k
        // minPrefix[r] = minimum prefix sum seen so far at position % k == r
        vector<long long> minPrefix(k, LLONG_MAX);
        minPrefix[0] = 0; // prefix[0] = 0, and 0 % k == 0
        
        long long prefix = 0; // Current prefix sum
        long long result = LLONG_MIN;
        
        for (int i = 0; i < n; i++) {
            prefix += nums[i]; // prefix[i+1]
            int remainder = (i + 1) % k;
            
            // If we have seen a prefix with the same remainder, we can form a valid subarray
            // Sum = prefix - minPrefix[remainder]
            // Length = (i+1) - start_position, which is divisible by k
            if (minPrefix[remainder] != LLONG_MAX)
                result = max(result, prefix - minPrefix[remainder]);
            
            // Update minimum prefix sum for this remainder
            minPrefix[remainder] = min(minPrefix[remainder], prefix);
        }
        
        return result;
    }
};