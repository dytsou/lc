class Solution:
    def regionsBySlashes(self, grid: list[str]) -> int:
        def diagonal_separate(i, j):
            graph[i * 3][j * 3 + 2] = 1
            graph[i * 3 + 1][j * 3 + 1] = 1
            graph[i * 3 + 2][j * 3] = 1
            
        def anti_diagonal_separate(i, j):
            graph[i * 3][j * 3] = 1
            graph[i * 3 + 1][j * 3 + 1] = 1
            graph[i * 3 + 2][j * 3 + 2] = 1
            
        def dfs(i, j):
            if i < 0 or i >= len(graph) or j < 0 or j >= len(graph[0]) or graph[i][j] == 1:
                return
            graph[i][j] = 1
            dfs(i - 1, j)
            dfs(i + 1, j)
            dfs(i, j - 1)
            dfs(i, j + 1)
               
        n = len(grid)
        ans = 0
        graph = [[0] * n * 3 for _ in range(n * 3)]
        for i in range(n):
            for j in range(n):
                if grid[i][j] == '/':
                    diagonal_separate(i, j)
                elif grid[i][j] == '\\':
                    anti_diagonal_separate(i, j)
        for i in range(n * 3):
            for j in range(n * 3):
                if graph[i][j] == 0:
                    dfs(i, j)
                    ans += 1
        return ans
            
            