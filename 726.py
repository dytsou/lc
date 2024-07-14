class Solution:
    def countOfAtoms(self, formula: str) -> str:
        stack = [{}]
        i = 0
        while i < len(formula):
            if formula[i] == '(':
                stack.append({})
                i += 1
            elif formula[i] == ')':
                i += 1
                j = i
                while j < len(formula) and formula[j].isdigit():
                    j += 1
                count = int(formula[i:j] or 1)
                i = j
                top = stack.pop()
                for atom, c in top.items():
                    stack[-1][atom] = stack[-1].get(atom, 0) + c * count
            else:
                j = i + 1
                while j < len(formula) and formula[j].islower():
                    j += 1
                atom = formula[i:j]
                i = j
                j = i
                while j < len(formula) and formula[j].isdigit():
                    j += 1
                count = int(formula[i:j] or 1)
                i = j
                stack[-1][atom] = stack[-1].get(atom, 0) + count
        ans = stack[-1]
        ans = sorted(ans.items())
        return ''.join(atom + (str(count) if count > 1 else '') for atom, count in ans)

if __name__ == '__main__':
    s = Solution()
    print(s.countOfAtoms(input()))