class Solution:
    def stoneGameII(self, piles: list[int]) -> int:
        n = len(piles)
        pile_sum = [0] * n
        dp = [[0] * n for _ in range(n)]
        def dfs(i, m):
            if i == n:
                return 0
            if 2 * m >= n - i:
                return pile_sum[i]
            if dp[i][m] != 0:
                return dp[i][m]
            res = 0
            for x in range(1, 2 * m + 1):
                if i + x > n:
                    break
                res = max(res, pile_sum[i] - dfs(i + x, max(m, x)))
            dp[i][m] = res
            return res
        pile_sum[-1] = piles[-1]
        for i in range(n - 2, -1, -1):
            pile_sum[i] = pile_sum[i + 1] + piles[i]
        return dfs(0, 1)
    
if __name__ == '__main__':
    s = Solution()
    piles = list(map(int, input().split()))
    print(s.stoneGameII(piles))