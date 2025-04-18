class Solution:
    def minSteps(self, n: int) -> int:
        if n == 1:
            return 0
        times = 0
        prime = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]
        for i in prime:
            while n % i == 0:
                times += i
                n = n // i
                if n == 1:
                    return times
        return times + n

if __name__ == '__main__':
    s = Solution()
    print(s.minSteps(int(input())))