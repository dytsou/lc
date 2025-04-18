class Solution:
    def minimumPushes(self, word: str) -> int:
        alphabets = [0] * 26
        for c in word:
            alphabets[ord(c) - ord('a')] += 1
        alphabets.sort(reverse=True)
        cnt, ans = 0, 0
        for i in alphabets:
            if i == 0:
                break
            ans += i * (cnt // 8 + 1)
            cnt += 1
        return ans

if __name__ == '__main__':
    string = input()
    s = Solution()
    print(s.minimumPushes(string))