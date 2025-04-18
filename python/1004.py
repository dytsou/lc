class Solution:
    def longestOnes(self, nums: list[int], k: int) -> int:
        i, j, n = 0, 0, len(nums)
        while j < n:
            if nums[j] == 0:
                k -= 1
            if k < 0:
                if nums[i] == 0:
                    k += 1
                i += 1
            j += 1
        return j - i