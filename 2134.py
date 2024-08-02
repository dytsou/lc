class Solution:
    def minSwaps(self, nums: list[int]) -> int:
        ones = sum(nums)
        n = len(nums)
        if ones == 0 or ones == n:
            return 0
        windows = [0] * n
        windows[0] = sum(nums[:ones])
        nums += nums
        for i in range(1, n):
            windows[i] = windows[i - 1] - nums[i - 1] + nums[i + ones - 1]
        return ones - max(windows)
    
if __name__ == '__main__':
    s = Solution()
    print(s.minSwaps(list(map(int, input().split()))))