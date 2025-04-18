class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        n = len(nums)
        p = 0
        q = 0
        while p < n:
            if nums[p] != 0:
                nums[q] = nums[p]
                q += 1
            p += 1
        while q < n:
            nums[q] = 0
            q += 1
        return nums

if __name__ == '__main__':
    nums = list(map(int, input().split()))
    s = Solution()
    print(s.moveZeroes(nums))