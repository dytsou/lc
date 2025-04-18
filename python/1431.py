class Solution:
    def kidsWithCandies(self, candies: list[int], extraCandies: int) -> list[bool]:
        maxCandies = max(candies)
        return [candy + extraCandies >= maxCandies for candy in candies]
    
if __name__ == '__main__':
    s = Solution()
    candies = list(map(int, input().split()))
    extraCandies = int(input())
    print(s.kidsWithCandies(candies, extraCandies))