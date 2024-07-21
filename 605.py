class Solution:
    def canPlaceFlowers(self, flowerbed: list[int], n: int) -> bool:
        s = len(flowerbed)
        if s == 1:
            return (flowerbed[0] + n) <= 1
        for i in range(s):
            if n == 0:
                break
            if i == 0:
                if flowerbed[0] == 0 and flowerbed[1] == 0:
                    flowerbed[0] += 1
                    n -= 1
                    i += 1
            elif i == s-1:
                if flowerbed[s-1] == 0 and flowerbed[s-2] == 0:
                    n -= 1
            elif flowerbed[i-1] == 0 and flowerbed[i] == 0 and flowerbed[i+1] == 0:
                flowerbed[i] += 1
                n -= 1
                i += 1
        return n == 0
    
if __name__ == '__main__':
    s = Solution();
    flowerbed = list(map(int, input().split()))
    n = int(input());
    print(s.canPlaceFlowers(flowerbed, n))
    