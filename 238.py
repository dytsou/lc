class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        n = len(nums)
        result = [1] * n
        left = 1
        right = 1
        for i in range(n):
            result[i] *= left
            result[n - i - 1] *= right
            left *= nums[i]
            right *= nums[n - i - 1]
        return result
    
if __name__ == '__main__':
    s = Solution()
    nums = list(map(int, input().split()))
    print(s.productExceptSelf(nums))