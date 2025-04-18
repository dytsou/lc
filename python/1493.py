class Solution:
    def longestSubarray(self, nums: list[int]) -> int:
        i, j, n, k = 0, 0, len(nums), 1
        while j < n:
            if nums[j] == 0:
                k -= 1
            if k < 0:
                if nums[i] == 0:
                    k += 1
                i += 1
            j += 1
        return j - i - 1

if __name__ == '__main__':
    s = Solution()
    nums = list(map(int, input().split()))
    print(s.longestSubarray(nums))