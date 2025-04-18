class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        def get_score(s: str, first: str, second: str, point: int) -> int:
            stack = []
            score = 0
            for c in s:
                if c == second and stack and stack[-1] == first:
                    score += point
                    stack.pop()
                else:
                    stack.append(c)
            new_str = ''.join(stack)
            return score, new_str, s != new_str
        ab = True
        ba = True
        ans = 0
        if x > y:
            while ab or ba:
                score1, s, ab = get_score(s, 'a', 'b', x)
                score2, s, ba = get_score(s, 'b', 'a', y)
                ans += score1 + score2
            return ans
        else:
            while ab or ba:
                score1, s, ba = get_score(s, 'b', 'a', y)
                score2, s, ab = get_score(s, 'a', 'b', x)
                ans += score1 + score2
            return ans

if __name__ == '__main__':
    s = Solution()
    print(s.maximumGain(input(), int(input()), int(input())))