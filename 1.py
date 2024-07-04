class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        hashtable = {}
        
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in hashtable:
                return [hashtable[complement], i]
            hashtable[nums[i]] = i
        return hashtable
    
if __name__ == "__main__":
    nums = input().split(',')
    nums = [int(i) for i in nums]
    target = int(input())
    solution = Solution()
    print(solution.twoSum(nums, target))