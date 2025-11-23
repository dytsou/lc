class Solution:
    def maxSumDivThree(self, nums: list[int]) -> int:
        rem1_min = [float('inf')] * 2
        rem2_min = [float('inf')] * 2
        sum = 0
        for num in nums:
            sum += num
            rem = num % 3
            if rem == 1:
                if num < rem1_min[0]:
                    rem1_min[1] = rem1_min[0]
                    rem1_min[0] = num
                elif num < rem1_min[1]:
                    rem1_min[1] = num
            elif rem == 2:
                if num < rem2_min[0]:
                    rem2_min[1] = rem2_min[0]
                    rem2_min[0] = num
                elif num < rem2_min[1]:
                    rem2_min[1] = num
        if sum % 3 == 0:
            return sum
        min_remove = self.getMinRemove(sum % 3, rem1_min, rem2_min)
        return sum - min_remove if min_remove != float('inf') else 0

    def getMinRemove(self, rem, rem1_min, rem2_min):
        if rem == 1:
            return min(rem1_min[0], rem2_min[0] + rem2_min[1])
        return min(rem2_min[0], rem1_min[0] + rem1_min[1])