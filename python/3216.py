class Solution:
    def getSmallestString(self, s: str) -> str:
        i = 0
        while i < len(s) - 1:
            if int(s[i]) % 2 == int(s[i+1]) % 2:
                if int(s[i]) > int(s[i+1]):
                    s = s[:i] + s[i+1] + s[i] + s[i+2:]
                    break
            i += 1
        return s
                    
if __name__ == '__main__':
    s = Solution()
    print(s.getSmallestString(input()))