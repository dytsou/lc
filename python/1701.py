class Solution:
    def averageWaitingTime(self, customers: list[list[int]]) -> float:
        start = 0
        end = 0
        wait = 0
        for arrive, cost in customers:
            start = max(end, arrive)
            end = start + cost
            wait += end - arrive
        return wait / len(customers)
        
if __name__ == '__main__':
    s = Solution()
    n = int(input())
    customers = []
    for _ in range(n):
        customers.append(list(map(int, input().split())))
    print(s.averageWaitingTime(customers))