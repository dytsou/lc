class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        
        // dp[i] = number of ways to partition ending at index i
        vector<int> dp(n, 0);
        // prefix[i] = dp[0] + dp[1] + ... + dp[i]
        vector<int> prefix(n, 0);
        
        // Deques to maintain indices of min and max elements in sliding window
        deque<int> minDeque, maxDeque;
        
        int left = 0; // leftmost valid starting position for current window
        
        for (int i = 0; i < n; i++) {
            // maintain min deque (increasing order)
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[i]) {
                minDeque.pop_back();
            }
            minDeque.push_back(i);
            
            // maintain max deque (decreasing order)
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[i]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(i);
            
            // shrink window from left until it's valid
            while (nums[maxDeque.front()] - nums[minDeque.front()] > k) {
                left++;
                // remove indices that are out of window
                while (!minDeque.empty() && minDeque.front() < left) {
                    minDeque.pop_front();
                }
                while (!maxDeque.empty() && maxDeque.front() < left) {
                    maxDeque.pop_front();
                }
            }
            
            // now all segments from left to i are valid
            // dp[i] = sum of (j == 0 ? 1 : dp[j-1]) for j from left to i
            // This equals: (left == 0 ? 1 : 0) + sum(dp[j] for j from max(left-1, 0) to i-1)
            if (left == 0) {
                // segment starting at 0: add 1 way
                dp[i] = (dp[i] + 1) % MOD;
            }
            // Add sum of dp[j] for j from max(left-1, 0) to i-1
            if (i > 0 && left <= i) {
                int startIdx = max(left - 1, 0);
                int endIdx = i - 1;
                if (startIdx <= endIdx) {
                    int sum = (prefix[endIdx] - (startIdx > 0 ? prefix[startIdx - 1] : 0) + MOD) % MOD;
                    dp[i] = (dp[i] + sum) % MOD;
                }
            }
            
            // update prefix sum
            prefix[i] = ((i > 0 ? prefix[i - 1] : 0) + dp[i]) % MOD;
        }
        
        return dp[n - 1];
    }
private:
    static const int MOD = 1e9 + 7;
};