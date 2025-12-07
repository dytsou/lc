from collections import deque
from typing import List


class Solution:
    def countPartitions(self, nums: List[int], k: int) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        dp = [0] * n
        prefix = [0] * n
        min_deque = deque()
        max_deque = deque()
        left = 0
        
        for i in range(n):
            num_i = nums[i]  # Cache to avoid repeated indexing
            
            # Maintain min deque (increasing order)
            while min_deque and nums[min_deque[-1]] >= num_i:
                min_deque.pop()
            min_deque.append(i)
            
            # Maintain max deque (decreasing order)
            while max_deque and nums[max_deque[-1]] <= num_i:
                max_deque.pop()
            max_deque.append(i)
            
            # Shrink window from left until valid
            while nums[max_deque[0]] - nums[min_deque[0]] > k:
                left += 1
                while min_deque and min_deque[0] < left:
                    min_deque.popleft()
                while max_deque and max_deque[0] < left:
                    max_deque.popleft()
            
            # Calculate dp[i]: sum of ways for all valid segments ending at i
            if left == 0:
                dp[i] = 1
            else:
                dp[i] = 0
            
            # Add sum of dp[j] for j from max(left-1, 0) to i-1
            if i > 0 and left <= i:
                start_idx = max(left - 1, 0)
                end_idx = i - 1
                if start_idx <= end_idx:
                    prefix_sum = prefix[end_idx]
                    if start_idx > 0:
                        prefix_sum = (prefix_sum - prefix[start_idx - 1] + MOD) % MOD
                    dp[i] = (dp[i] + prefix_sum) % MOD
            
            # Update prefix sum
            prefix[i] = ((prefix[i - 1] if i > 0 else 0) + dp[i]) % MOD
        
        return dp[n - 1]