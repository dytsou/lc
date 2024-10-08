import math
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        return "" if str1+str2 != str2+str1 else str1[:math.gcd(len(str1), len(str2))]
    
if __name__ == '__main__':
    s = Solution
    print(s.gcdOfStrings(s, input(), input()))    