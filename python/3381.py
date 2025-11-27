from typing import List

class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        min_prefix = [float('inf')] * k
        min_prefix[0] = 0
        prefix = 0
        result = -float('inf')
        for i in range(n):
            prefix += nums[i]
            remainder = (i + 1) % k
            if min_prefix[remainder] != float('inf'):
                result = max(result, prefix - min_prefix[remainder])
            min_prefix[remainder] = min(min_prefix[remainder], prefix)
        return result