class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        curr = sum(1 for c in s[:k] if c in 'aeiou')
        max_vowels = curr
        for i in range(k, len(s)):
            curr += s[i] in 'aeiou'
            curr -= s[i - k] in 'aeiou'
            max_vowels = max(max_vowels, curr)
        return max_vowels
    
if __name__ == '__main__':
    s = input()
    k = int(input())
    print(Solution().maxVowels(s, k))