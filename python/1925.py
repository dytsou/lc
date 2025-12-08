from math import gcd

class Solution:
    def countTriples(self, n: int) -> int:
        result = 0
        for a in range(2, n + 1):
            for b in range(1, a):
                if gcd(a, b) == 1 and (a - b) % 2 == 1:
                    c = a * a + b * b
                    if c > n:
                        break
                    result += 2 * (n // c)
        return result