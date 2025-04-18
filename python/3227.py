class Solution:
    def doesAliceWin(self, s: str) -> bool:
        for c in s:
            if c in ['a', 'e', 'i', 'o', 'u']:
                return True
        return False
        
if __name__ == '__main__':
    s = Solution()
    print(s.doesAliceWin(input()))