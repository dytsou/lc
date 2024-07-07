class Solution:
    def longestPalindrome(self, s: str) -> str:
        def expandAroundCenter(left, right):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            return s[left+1 : right]
        
        if len(s) < 2:
            return s
        if len(s) == 2:
            if s[0] == s[1]:
                return s
            return s[0]
        
        ans = ''
        for i in range(len(s)):
            oddAns = expandAroundCenter(i, i)
            evenAns = expandAroundCenter(i, i+1)
            if len(oddAns) > len(ans):
                ans = oddAns
            if len(evenAns) > len(ans):
                ans = evenAns
        return ans
        
if __name__ == '__main__':
    s = Solution()
    print(s.longestPalindrome(input()))