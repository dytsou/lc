class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        
        // Calculate total sum modulo p
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        
        // If already divisible, return 0
        int target = total % p;
        if(target == 0) {
            return 0;
        }
        
        // Use prefix sum with modulo to find smallest subarray with remainder = target
        unordered_map<int, int> lastIndex; // maps prefix_sum % p -> last index
        lastIndex[0] = -1; // prefix sum 0 at index -1 (before start)
        
        long long prefix = 0;
        int minLen = n;
        
        for(int i = 0; i < n; i++) {
            prefix = (prefix + nums[i]) % p;
            
            // We want to find a subarray with remainder = target
            // If prefix % p = r, we need previous prefix % p = (r - target + p) % p
            int need = (prefix - target + p) % p;
            
            if(lastIndex.count(need)) {
                minLen = min(minLen, i - lastIndex[need]);
            }
            
            lastIndex[prefix] = i;
        }
        
        return minLen == n ? -1 : minLen;
    }
};