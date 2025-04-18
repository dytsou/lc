class Solution:
    def canBeEqual(self, target: list[int], arr: list[int]) -> bool:
        return sorted(target) == sorted(arr)
    
if __name__ == '__main__':
    target = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    print(Solution().canBeEqual(target, arr))