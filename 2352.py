class Solution:
    def equalPairs(self, grid: list[list[int]]) -> int:
        def int2str(num: int) -> str:
            return f'{num:03d}'
        rows, cols = [], []
        for row in grid:
            rows.append(''.join(map(int2str, row)))
        for col in zip(*grid):
            cols.append(''.join(map(int2str, col)))
        return sum(row == col for row in rows for col in cols)