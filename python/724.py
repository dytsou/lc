class Solution:
    def pivotIndex(self, nums: list[int]) -> int:
        leftSum, rightSum = 0, sum(nums)
        for i, num in enumerate(nums):
            rightSum -= num
            if leftSum == rightSum:
                return i
            leftSum += num
        return -1
    
if __name__ == '__main__':
    s = Solution()
    nums = list(map(int, input().split()))
    print(s.pivotIndex(nums))