class Solution:
    def maxArea(self, height: list[int]) -> int:
        max_area = 0
        p = 0
        q = len(height) - 1
        while p < q:
            area = min(height[p], height[q]) * (q - p)
            max_area = max(max_area, area)
            if height[p] < height[q]:
                p += 1
            else:
                q -= 1
        return max_area
    
if __name__ == '__main__':
    s = Solution()
    print(s.maxArea(list(map(int, input().split()))))