class Solution:
    def romanToInt(self, s: str) -> int:
        roman = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M':1000}
        ans = 0
        for i in range(len(s)):
            ans += roman[s[i]]
            ans -= 2*roman[s[i-1]] if i > 0 and roman[s[i]] > roman[s[i-1]] else 0
        return ans
       
if __name__ == '__main__':
    s = Solution()
    n = input()
    print(s.romanToInt(n))