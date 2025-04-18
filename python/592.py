import re
from math import gcd

class Solution:
    def fractionAddition(self, expression: str) -> str:
        
        def lcm(a, b):
            return a * b // gcd(a, b)
        
        def add(a, b):
            a1, a2 = a
            b1, b2 = b
            l = lcm(a2, b2)
            return (a1 * l // a2 + b1 * l // b2, l)
        
        def parse(s):
            a, b = map(int, s.split('/'))
            return (a, b)
        
        # [+-]?: match one or zero + or -, representing the sign of the fraction
        # \d+: match one or more digits, representing the numerator and denominator
        nums = list(map(parse, re.findall(r'[+-]?\d+/\d+', expression)))
        ans = (0, 1) # means 0/1
        for num in nums:
            ans = add(ans, num)
        a, b = ans
        g = gcd(a, b)
        return f'{a // g}/{b // g}'
    
if __name__ == '__main__':
    s = Solution()
    print(s.fractionAddition(input()))