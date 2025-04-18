class Solution:
    def construct2DArray(self, original: list[int], m: int, n: int) -> list[list[int]]:
        if len(original) != m * n:
            return []
        return [original[i * n : (i + 1) * n] for i in range(m)]

if __name__ == '__main__':
    s = Solution()
    arr = list(map(int, input().split()))
    m = int(input())
    n = int(input())
    print(s.construct2DArray(arr, m, n))