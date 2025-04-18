class Solution:
    def uniqueOccurrences(self, arr: list[int]) -> bool:
        map = {}
        for i in arr:
            if i in map:
                map[i] += 1
            else:
                map[i] = 1
        return len(map) == len(set(map.values()))
    
if __name__ == '__main__':
    print(Solution().uniqueOccurrences(list(map(int, input().split()))))