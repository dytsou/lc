from typing import List

class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        while True:
            flag = 1
            for num in nums:
                if num == original:
                    original *= 2
                    flag = 0
                    break
            if flag:
                return original