class Solution:
    def minDays(self, grid: list[list[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        def count_islands(grid):
            def dfs(x, y):
                if x < 0 or x >= n or y < 0 or y >= m or grid[x][y] != 1:
                    return
                grid[x][y] = 2
                dfs(x + 1, y)
                dfs(x - 1, y)
                dfs(x, y + 1)
                dfs(x, y - 1)
                
            count = 0
            for i in range(n):
                for j in range(m):
                    if grid[i][j] == 1:
                        dfs(i, j)
                        count += 1
            for i in range(n):
                for j in range(m):
                    if grid[i][j] == 2:
                        grid[i][j] = 1
            return count
        
        if count_islands(grid) != 1:
            return 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    grid[i][j] = 0
                    if count_islands(grid) != 1:
                        return 1
                    grid[i][j] = 1
        return 2
    
if __name__ == '__main__':
    [n, m] = list(map(int, input().split()))
    grid = [list(map(int, input().split())) for _ in range(n)]
    print(Solution().minDays(grid))