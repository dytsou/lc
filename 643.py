class Solution:
    def findMaxAverage(self, nums: list[int], k: int) -> float:
        n = len(nums)
        curr = sum(nums[:k])
        currMax = curr
        for i in range(1, n - k + 1):
            curr += nums[i + k - 1] - nums[i - 1]
            currMax = max(currMax, curr)
        return currMax / k
        
if __name__ == '__main__':
    nums = list(map(int, input().split()))
    k = int(input())
    s = Solution()
    print(s.findMaxAverage(nums, k))
    