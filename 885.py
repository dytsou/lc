class Solution:
    def spiralMatrixIII(self, rows: int, cols: int, rStart: int, cStart: int) -> list[list[int]]:
        ans = [[rStart, cStart]]
        all_blocks = rows * cols
        radius = 1
        
        while len(ans) < all_blocks:
            # go right
            for _ in range(radius):
                cStart += 1
                if 0 <= rStart < rows and 0 <= cStart < cols:
                    ans.append([rStart, cStart])
            # go down
            for _ in range(radius):
                rStart += 1
                if 0 <= rStart < rows and 0 <= cStart < cols:
                    ans.append([rStart, cStart])
            radius += 1
            # go left
            for _ in range(radius):
                cStart -= 1
                if 0 <= rStart < rows and 0 <= cStart < cols:
                    ans.append([rStart, cStart])
            # go up
            for _ in range(radius):
                rStart -= 1
                if 0 <= rStart < rows and 0 <= cStart < cols:
                    ans.append([rStart, cStart])
            radius += 1
        
        return ans

if __name__ == '__main__':
    rows, cols, rStart, cStart = map(int, input().split()) 
    print(Solution().spiralMatrixIII(rows, cols, rStart, cStart))