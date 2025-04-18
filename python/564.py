class Solution:
    def nearestPalindromic(self, n: str) -> str:
        num = int(n)
        if num <= 10:
            return str(num - 1)
        if num == 11:
            return "9"

        length = len(n)
        left_half = int(n[:(length + 1) // 2])
        candidates = [
            self.make_pal(left_half - 1, length % 2 == 0),
            self.make_pal(left_half, length % 2 == 0),
            self.make_pal(left_half + 1, length % 2 == 0),
            10**(length - 1) - 1, # e.g. 999
            10**length + 1 # e.g. 101
        ]
        nearest = 0
        min_diff = float('inf')
        for candidate in candidates:
            if candidate == num:
                continue
            diff = abs(candidate - num)
            if diff < min_diff or (diff == min_diff and candidate < nearest):
                min_diff = diff
                nearest = candidate
        return str(nearest)

    def make_pal(self, left_half: int, is_even_length: bool) -> int:
        palindrome = left_half  
        if not is_even_length:
            left_half //= 10
        while left_half > 0:
            palindrome = palindrome * 10 + left_half % 10
            left_half //= 10
        return palindrome
    
if __name__ == '__main__':
    s = Solution()
    print(s.nearestPalindromic(input()))