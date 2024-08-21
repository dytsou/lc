class Solution:
    def strangePrinter(self, s: str) -> int:
        n = len(s)
        dp = [[-1] * n for _ in range(n)]
        
        def flips(l, r):
            if l > r:
                return 0
            if dp[l][r] != -1:
                return dp[l][r]
            i = l
            while i + 1 <= r and s[i] == s[i + 1]:
                i += 1
            res = 1 + flips(i + 1, r)
            for j in range(i + 1, r + 1):
                if s[j] == s[i]:
                    res = min(res, flips(j, r) + flips(i + 1, j - 1))
            dp[l][r] = res
            return res
        return flips(0, n - 1)
    
if __name__ == '__main__':
    s = Solution()
    print(s.strangePrinter(input()))