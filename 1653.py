class Solution:
    def minimumDeletions(self, s: str) -> int:
        cntA = s.count('a')
        cntB = (s[0] == 'b')
        cnt = cntA + cntB - 1
        for i in range(1, len(s)):
            if s[i] == 'b':
                cntB += 1
            if s[i - 1] == 'a':
                cntA -= 1
            cnt = min(cnt, cntA + cntB - 1)
        return cnt
    
if __name__ == '__main__':
    s = Solution()
    print(s.minimumDeletions(input()))