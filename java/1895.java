class Solution {
    public int largestMagicSquare(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;

        int max = Math.min(rows, cols);

        for (int size = max; size >= 2; size--) {
            for (int r = 0; r + size - 1 < rows; r++) {
                for (int c = 0; c + size - 1 < cols; c++) {
                    if (isMagic(grid, r, c, size)) {
                        return size;
                    }
                }
            }
        }

        return 1;
    }

    private boolean isMagic(int[][] grid, int r, int c, int size) {
        int targetSum = 0;

        // Sum of first row
        for (int j = 0; j < size; j++) {
            targetSum += grid[r][c + j];
        }

        int diag1 = 0, diag2 = 0;
        for (int i = 0; i < size; i++) {
            diag1 += grid[r + i][c + i];  
            diag2 += grid[r + i][c + size - 1 - i];
        }
        if (diag1 != targetSum || diag2 != targetSum) return false;

        for (int i = 1; i < size; i++) {
            int sum = 0;
            for (int j = 0; j < size; j++) {
                sum += grid[r + i][c + j];
            }
            if (sum != targetSum) return false;
        }

        for (int j = 0; j < size; j++) {
            int sum = 0;
            for (int i = 0; i < size; i++) {
                sum += grid[r + i][c + j];
            }
            if (sum != targetSum) return false;
        }

        return true;
    }
}