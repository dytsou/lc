from collections import Counter

class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1) != len(word2):
            return False
        if set(word1) != set(word2):
            return False
        return sorted(Counter(word1).values()) == sorted(Counter(word2).values()) and sorted(Counter(word1).keys()) == sorted(Counter(word2).keys())
    
if __name__ == '__main__':
    s = Solution()
    [word1, word2] = list(input().split())
    print(s.closeStrings(word1, word2))