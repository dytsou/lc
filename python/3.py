class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_len = 0
        start = 0
        char_idx = {}
        for i, c in enumerate(s): # enumerate() returns index and value of each element in the list
            if c in char_idx:
                start = max(start, char_idx[c] + 1) 
            max_len = max(max_len, i - start + 1)
            char_idx[c] = i
        return max_len
        
if __name__ == '__main__':
    s = Solution()
    print(s.lengthOfLongestSubstring(input()))