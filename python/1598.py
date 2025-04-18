class Solution:
    def minOperations(self, logs: list[str]) -> int:
        d = 0
        for log in logs:
            d = 0 if log == '../' and d == 0 else d - 1 if log == '../' else d + 1 if log != './' else d
        return d
        

if __name__ == '__main__':
    s = Solution()
    logs = input().split()
    print(s.minOperations(logs))