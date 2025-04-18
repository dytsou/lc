class Solution:
    def nthUglyNumber(self, n: int) -> int:
        dp = [1] * n
        two_ptr, three_ptr, five_ptr = 0, 0, 0
        two_mul, three_mul, five_mul = 2, 3, 5
        for i in range(1, n):
            dp[i] = min(two_mul, three_mul, five_mul)
            if dp[i] == two_mul:
                two_ptr += 1
                two_mul = dp[two_ptr] * 2
            if dp[i] == three_mul:
                three_ptr += 1
                three_mul = dp[three_ptr] * 3
            if dp[i] == five_mul:
                five_ptr += 1
                five_mul = dp[five_ptr] * 5
        return dp[-1]
    
if __name__ == '__main__':
    s = Solution()
    print(s.nthUglyNumber(int(input())))