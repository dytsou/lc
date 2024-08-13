class Solution:
    def decodeString(self, s: str) -> str:
        for i, c in enumerate(s):
            if c == ']':
                end = i
                while s[end] != '[':
                    end -= 1
                start = end
                while start > 0 and s[start - 1].isdigit():
                    start -= 1
                s = s[:start] + int(s[start:end]) * s[end + 1:i] + s[i + 1:]
                return self.decodeString(s)
        return s
    
if __name__ == '__main__':
    s = Solution()
    print(s.decodeString(input()))