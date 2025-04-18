class Solution:
    def checkString(self, s: str) -> bool:
        existB = False
        for i in range(len(s)):
            if s[i] == 'b':
                existB = True
            elif existB:
                return False
        return True
    
if __name__ == '__main__':
    s = Solution()
    print(s.checkString(input()))