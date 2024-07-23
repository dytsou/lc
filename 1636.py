class Solution:
    def frequencySort(self, nums: list[int]) -> list[int]:
        freq = {}
        for num in nums:
            freq[num] = freq.get(num, 0) + 1
        return sorted(nums, key=lambda x: (freq[x], -x))
    
if __name__ == '__main__':
    s = Solution()
    print(s.frequencySort(list(map(int, input().split()))))
        