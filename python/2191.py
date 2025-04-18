class Solution:
    def sortJumbled(self, mapping: list[int], nums: list[int]) -> list[int]:
        def mapping_num(num: int, mapping: list[int]) -> int:
            return int(''.join([str(mapping[int(i)]) for i in str(num)]))
        return sorted(nums, key=lambda x: mapping_num(x, mapping))
    
if __name__ == '__main__':
    s = Solution()
    mapping = list(map(int, input().split()))
    nums = list(map(int, input().split()))
    print(s.sortJumbled(mapping, nums))