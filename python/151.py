class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(s.split()[::-1])
    
if __name__ == '__main__':
    s = Solution()
    print(s.reverseWords(input()))