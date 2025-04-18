class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        ans = ['' for _ in range(numRows)]
        idx = 0
        flag = -1
        for i in range(len(s)):
            ans[idx] += s[i]
            if idx == 0 or idx == numRows-1:
                flag = -flag
            idx += flag
        return ''.join(ans)
        
if __name__ == "__main__":
    s = Solution()
    string = input()
    numRows = int(input())
    print(s.convert(string, numRows))