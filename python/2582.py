class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        # if n == 1:
        #     return 1
        # location = time % (2 * n - 2) + 1  # 1-based
        # return location if location <= n else 2 * n - location
        return 1 if n == 1 else (time % (2 * n - 2) + 1 if time % (2 * n - 2) + 1 <= n else 2 * n - time % (2 * n - 2) - 1)
        
if __name__ == '__main__':
    s = Solution()
    n = int(input())
    time = int(input())
    print(s.passThePillow(n, time))