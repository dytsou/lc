class Solution:
    def numMagicSquaresInside(self, grid: list[list[int]]) -> int:
        def find_magic_square(i, j):
            s = ''.join(str(grid[x][y]) for x in range(i, i + 3) for y in range(j, j + 3))
            if not all(s.count(c) == 1 for c in '123456789'): # exist 1-9
                return 0
            if not all(sum(grid[x][y] for x in range(i, i + 3)) == 15 for y in range(j, j + 3)): # row sum = 15
                return 0
            if not all(sum(grid[x][y] for y in range(j, j + 3)) == 15 for x in range(i, i + 3)): # col sum = 15
                return 0
            if sum(grid[x][y] for x, y in zip(range(i, i + 3), range(j, j + 3))) != 15: # diagonal sum = 15
                return 0
            if sum(grid[x][y] for x, y in zip(range(i + 2, i - 1, -1), range(j, j + 3))) != 15: # anti-diagonal sum = 15
                return 0
            return 1

        return sum(
            find_magic_square(i, j) 
            for i in range(len(grid) - 2) 
            for j in range(len(grid[0]) - 2) 
            if grid[i + 1][j + 1] == 5
        )
        
if __name__ == '__main__':
    s = Solution()
    n, m = int(input()), int(input())
    grid = [list(map(int, input().split())) for _ in range(n)]
    print(s.numMagicSquaresInside(grid))