class Solution:
    def removeStars(self, s: str) -> str:
        ans = []
        for c in s:
            if c == '*':
                if len(ans) > 0:
                    ans.pop()
            else:
                ans.append(c)
        return ''.join(ans)
    
if __name__ == '__name__':
    print(Solution().removeStars(input()))