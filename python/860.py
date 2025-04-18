class Solution:
    def lemonadeChange(self, bills: list[int]) -> bool:
        fives, tens = 0, 0
        for i, _ in enumerate(bills):
            if bills[i] == 5:
                fives += 1
            elif bills[i] == 10:
                tens += 1
                fives -= 1
            elif tens > 0:
                tens -= 1
                fives -= 1
            else:
                fives -= 3
                
            if fives < 0:
                return False
        return True
    
if __name__ == '__main__':
    s = Solution()
    bills = list(map(int, input().split()))
    print(s.lemonadeChange(bills))