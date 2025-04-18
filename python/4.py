class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        mid = (len(nums1) + len(nums2)) // 2
        merged = []
        i = 0
        j = 0
        while len(merged) <= mid:
            if i < len(nums1) and j < len(nums2):
                if nums1[i] <= nums2[j]:
                    merged.append(nums1[i])
                    i += 1
                else:
                    merged.append(nums2[j])
                    j += 1
            elif i < len(nums1):
                merged.append(nums1[i])
                i += 1
            else:
                merged.append(nums2[j])
                j += 1
        return (merged[-1] + merged[-2]) / 2 if (len(nums1) + len(nums2)) % 2 == 0 else merged[-1]
        
        
if __name__ == '__main__':
    s = Solution()
    nums1 = [int(x) for x in input().split()]
    nums2 = [int(x) for x in input().split()]
    print(s.findMedianSortedArrays(nums1, nums2))