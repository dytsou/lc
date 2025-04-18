class Solution:
    def asteroidCollision(self, asteroids: list[int]) -> list[int]:
        posIdx = 0
        ans = []
        for asteroid in asteroids:    
            if asteroid > 0:
                break
            ans.append(asteroid)
            posIdx += 1
        
        for i in range(posIdx, len(asteroids)):
            asteroid = asteroids[i]
            if asteroid > 0:
                ans.append(asteroid)
            else:
                while True:
                    if len(ans) == 0:
                        ans.append(asteroid)
                        break
                    if ans[-1] < 0:
                        ans.append(asteroid)
                        break
                    if ans[-1] < -(asteroid):
                        ans.pop()
                        continue
                    elif ans[-1] == -(asteroid):
                        ans.pop()
                        break
                    else:
                        break
        return ans
    
if __name__ == '__main__':
    asteroids = list(map(int, input().split()))
    print(Solution().asteroidCollision(asteroids))
            