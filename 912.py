class Solution:
    def sortArray(self, nums: list[int]) -> list[int]: 
        def mergeSort(left, right):
            if left >= right:
                return
            mid = left + (right - left) // 2
            mergeSort(left, mid)
            mergeSort(mid+1, right)
            a, b = left, mid+1
            merged = []
            while a <= mid and b <= right:
                if nums[a] < nums[b]:
                    merged.append(nums[a])
                    a += 1
                else:
                    merged.append(nums[b])
                    b += 1
            while a <= mid:
                merged.append(nums[a])
                a += 1
            while b <= right:
                merged.append(nums[b])
                b += 1
            nums[left : right+1] = merged
            return
        n = len(nums)
        mergeSort(0, n-1)
        return nums

if __name__ == '__main__':
    s = Solution()
    nums = list(map(int, input().split()))
    print(s.sortArray(nums))