class Solution:
    def luckyNumbers (self, matrix: list[list[int]]) -> list[int]:
        row_min = [min(row) for row in matrix]
        col_max = [max(col) for col in zip(*matrix)]
        return list(set(row_min) & set(col_max))
       
if __name__ == '__main__':
    n, m = int(input()), int(input())
    matrix = [list(map(int, input().split())) for _ in range(n)]
    s = Solution()
    print(s.luckyNumbers(matrix)) 