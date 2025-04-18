class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        p = 0
        q = 0
        while p < len(s) and q < len(t):
            if s[p] == t[q]:
                p += 1
            q += 1
        return p == len(s)
    
if __name__ == '__main__':
    s = input()
    t = input()
    sol = Solution()
    print(sol.isSubsequence(s, t))