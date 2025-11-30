class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        n = len(nums)
        total = sum(nums)
        if total % p == 0:
            return 0
        target = total % p
        prefix = 0
        last_index = {0: -1} # dictionary
        min_len = n
        for i in range(n):
            prefix = (prefix + nums[i]) % p
            need = (prefix - target + p) % p
            if need in last_index:
                min_len = min(min_len, i - last_index[need])
            last_index[prefix] = i
        return min_len if min_len != n else -1