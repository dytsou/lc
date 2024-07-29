class Solution:
    def numTeams(self, rating: list[int]) -> int:
        n = len(rating)
        ans = 0
        for i in range(n):
            left_less = left_more = right_less = right_more = 0
            for j in range(i):
                if rating[j] < rating[i]:
                    left_less += 1
                elif rating[j] > rating[i]:
                    left_more += 1
            for k in range(i + 1, n):
                if rating[k] < rating[i]:
                    right_less += 1
                elif rating[k] > rating[i]:
                    right_more += 1
            ans += left_less * right_more + left_more * right_less
        return ans
    
if __name__ == '__main__':
    rating = list(map(int, input().split()))
    print(Solution().numTeams(rating))