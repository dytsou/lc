class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        seen = [set() for _ in range(26)]
        processed = [False] * 26
        count = 0
        
        for i in range(len(s) - 2):
            outer_char = s[i]
            outer_idx = ord(outer_char) - ord('a')
            
            if processed[outer_idx]:
                continue
            
            processed[outer_idx] = True
            first_idx = i
            
            last_idx = s.rfind(outer_char, first_idx + 2)
            
            if last_idx == -1:
                continue
            
            middle_chars = set(s[first_idx + 1:last_idx])
            count += len(middle_chars)
            seen[outer_idx] = middle_chars
        
        return count

