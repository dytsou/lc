class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        curr = 0
        n = len(nums)
        result = [False] * n
        for i, num in enumerate(nums):
            curr = (curr * 2 + num) % 5
            if curr == 0:
                result[i] = True
        return result