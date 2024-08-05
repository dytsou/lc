class Solution:
    def largestAltitude(self, gain: list[int]) -> int:
        curr, highest = 0, 0
        for i in gain:
            curr += i
            highest = max(highest, curr)
        return highest
    
if __name__ == '__main__':
    gain = list(map(int, input().split()))
    print(Solution().largestAltitude(gain))