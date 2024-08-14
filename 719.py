class Solution:
    def smallestDistancePair(self, nums: list[int], k: int) -> int:
        nums.sort()
        left, right = 0, nums[-1] - nums[0]
        while left < right:
            mid = (left + right) // 2
            count, start = 0, 0
            for i in range(len(nums)):
                while nums[i] - nums[start] > mid:
                    start += 1
                count += i - start
            if count < k:
                left = mid + 1
            else:
                right = mid
        return left
    
if __name__ == '__main__':
    nums = list(map(int, input().split()))
    k = int(input())
    s = Solution()
    print(s.smallestDistancePair(nums, k))