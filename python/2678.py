class Solution:
    def countSeniors(self, details: list[str]) -> int:
        ans = 0
        for detail in details:
            ans += ((detail[11] > '6') or (detail[11] == '6' and detail[12] > '0'))
        return ans
    
if __name__ == '__main__':
    n = int(input())
    details = [input() for _ in range(n)]
    s = Solution()
    print(s.countSeniors(details))