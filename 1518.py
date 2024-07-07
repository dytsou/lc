class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        ans = numBottles
        while numBottles >= numExchange:
            ans += numBottles // numExchange
            numBottles = (numBottles // numExchange) + (numBottles % numExchange)
        return ans
    
if __name__ == '__main__':
    numBottles = int(input())
    numExchange = int(input())
    s = Solution()
    print(s.numWaterBottles(numBottles, numExchange))