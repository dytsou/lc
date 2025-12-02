from typing import List


class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        yCounts = {}
        for point in points:
            yCounts[point[1]] = yCounts.get(point[1], 0) + 1
        sum = 0
        sumSquares = 0
        for _, count in yCounts.items():
            if count <= 1:
                continue
            c = count
            pairs = c * (c - 1) // 2
            sum += pairs
            sumSquares += pairs * pairs
        return (sum * sum - sumSquares) // 2 % (10**9 + 7)