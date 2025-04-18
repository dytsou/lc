class Solution:
    def restoreMatrix(self, rowSum: list[int], colSum: list[int]) -> list[list[int]]:
        n, m = len(rowSum), len(colSum)
        matrix = [[0] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                matrix[i][j] = min(rowSum[i], colSum[j])
                rowSum[i] -= matrix[i][j]
                colSum[j] -= matrix[i][j]
        return matrix
        
if __name__ == '__main__':
    s = Solution()
    rowSum = list(map(int, input().split()))
    colSum = list(map(int, input().split()))
    print(s.restoreMatrix(rowSum, colSum))