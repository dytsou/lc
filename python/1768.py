class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        return ''.join(a + b for a, b in zip_longest(word1, word2, fillvalue=''))
    
if __name__ == '__main__':
    s = Solution()
    print(s.mergeAlternately(input(), input()))