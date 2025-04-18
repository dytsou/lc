class Solution:
    def reverseParentheses(self, s: str) -> str:
        ans = []
        last_para = []
        for i in range(len(s)):
            if s[i] == '(':
                last_para.append(len(ans))
            elif s[i] == ')':
                loc = last_para.pop()
                tmp = ans[loc:]
                ans = ans[:loc] + tmp[::-1]
            else:
                ans.append(s[i])
        return ''.join(ans)

if __name__ == '__main__':
    s = Solution()
    print(s.reverseParentheses(input()))