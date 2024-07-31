class Solution:
    def minHeightShelves(self, books: list[list[int]], shelfWidth: int) -> int:
        n = len(books)
        dp = [float('inf')] * (n+1)
        dp[0] = 0
        for i in range(1, n+1):
            width, height = 0, 0
            j = i
            while j > 0:
                width += books[j-1][0]
                if width > shelfWidth:
                    break
                height = max(height, books[j-1][1])
                dp[i] = min(dp[i], dp[j-1] + height)
                j -= 1
        return dp[n]
    
if __name__ == '__main__':
    n = int(input())
    books = [list(map(int, input().split())) for _ in range(n)]
    shelfWidth = int(input())
    s = Solution()
    print(s.minHeightShelves(books, shelfWidth))
            