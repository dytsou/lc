class Solution:
    def findDifference(self, nums1: list[int], nums2: list[int]) -> list[list[int]]:
        nums1, nums2 = set(nums1), set(nums2)
        ans1 = nums1.difference(nums2)
        ans2 = nums2.difference(nums1)
        return [list(ans1), list(ans2)]
        
    
if __name__ == '__main__':
    nums1 = list(map(int, input().split()))
    nums2 = list(map(int, input().split()))
    print(Solution().findDifference(nums1, nums2))