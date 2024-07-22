class Solution:
    def sortPeople(self, names: list[str], heights: list[int]) -> list[str]:
        people = list(zip(names, heights))
        people.sort(key=lambda x: (-x[1], x[0]))
        return [name for name, _ in people]
    
if __name__ == '__main__':
    names = list(input().strip().split())
    heights = list(map(int, input().strip().split()))
    print(Solution().sortPeople(names, heights))