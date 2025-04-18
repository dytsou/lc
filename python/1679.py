class Solution:
    def maxOperations(self, nums: list[int], k: int) -> int:
        nums.sort()
        i, j, ans = 0, len(nums) - 1, 0
        while i < j:
            if nums[i] + nums[j] == k:
                ans += 1
                i += 1
                j -= 1
            elif nums[i] + nums[j] < k:
                i += 1
            else:
                j -= 1
        return ans

if __name__ == '__main__':
    nums = list(map(int, input().split()))
    k = int(input())
    s = Solution()
    print(s.maxOperations(nums, k))