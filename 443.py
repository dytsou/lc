class Solution:
    def compress(self, chars: list[str]) -> int:
        charList = list()
        charCount = list()
        for c in chars:
            if charList and charList[-1] == c:
                charCount[-1] += 1
            else:
                charList.append(c)
                charCount.append(1)
        chars.clear()
        for i in range(len(charList)):
            chars.append(charList[i])
            if charCount[i] > 1:
                for c in str(charCount[i]):
                    chars.append(c)
        return len(chars)