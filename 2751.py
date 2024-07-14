class Solution:
    def survivedRobotsHealths(self, positions: list[int], healths: list[int], directions: str) -> list[int]:
        n = len(positions)
        robots = [(positions[i], i) for i in range(n)]
        robots.sort()
        
        stack = []
        for i in range(n):
            idx = robots[i][1]
            if directions[idx] == 'R':
                stack.append(idx)
            else:
                while stack:
                    if healths[stack[-1]] > healths[idx]:
                        healths[stack[-1]] -= 1
                        healths[idx] = -1
                        break
                    elif healths[stack[-1]] < healths[idx]:
                        healths[idx] -= 1
                        healths[stack.pop()] = -1
                    else:
                        healths[idx] = -1
                        healths[stack.pop()] = -1
                        break
        result = []
        for i in range(n):
            if healths[i] > 0:
                result.append(healths[i])
        return result

if __name__ == '__main__':
    s = Solution()
    positions = list(map(int, input().strip().split()))
    healths = list(map(int, input().strip().split()))
    directions = input()
    print(s.survivedRobotsHealths(positions, healths, directions))