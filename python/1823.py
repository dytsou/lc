class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        circle = [i for i in range(1, n+1)]
        idx = 0
        while len(circle) > 1:
            idx = (idx + k - 1) % len(circle)
            circle.pop(idx)
        return circle[0]
        
        
if __name__ == '__main__':
    s = Solution()
    n = int(input())
    k = int(input())
    print(s.findTheWinner(n, k))