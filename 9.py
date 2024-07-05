class Solution:
    def isPalindrome(self, x: int) -> bool:
        return x>=0 and str(x) == str(x)[::-1]
        
        
if __name__ == "__main__":
    s = Solution()
    x = int(input())
    print(s.isPalindrome(x))