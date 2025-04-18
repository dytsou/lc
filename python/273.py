class Solution:
    def numberToWords(self, num: int) -> str:
        def intToWords(num: int) -> str:
            if num == 0:
                return "Zero"
            elif num == 1:
                return "One"
            elif num == 2:
                return "Two"
            elif num == 3:
                return "Three"
            elif num == 4:
                return "Four"
            elif num == 5:
                return "Five"
            elif num == 6:
                return "Six"
            elif num == 7:
                return "Seven"
            elif num == 8:
                return "Eight"
            elif num == 9:
                return "Nine"
            elif num == 10:
                return "Ten"
            elif num == 11:
                return "Eleven"
            elif num == 12:
                return "Twelve"
            elif num == 13:
                return "Thirteen"
            elif num == 14:
                return "Fourteen"
            elif num == 15:
                return "Fifteen"
            elif num == 16:
                return "Sixteen"
            elif num == 17:
                return "Seventeen"
            elif num == 18:
                return "Eighteen"
            elif num == 19:
                return "Nineteen"
            elif num == 20:
                return "Twenty"
            elif num == 30:
                return "Thirty"
            elif num == 40:
                return "Forty"
            elif num == 50:
                return "Fifty"
            elif num == 60:
                return "Sixty"
            elif num == 70:
                return "Seventy"
            elif num == 80:
                return "Eighty"
            elif num == 90:
                return "Ninety"
            return ""

        def seperateToThree(num: int) -> list[int]:
            res = []
            while num:
                res.append(num % 1000)
                num //= 1000
            return res[::-1]

        def threeToWords(num: int) -> list[str]:
            res = []
            if num >= 100:
                res.append(intToWords(num // 100))
                res.append("Hundred")
                num %= 100
            if num >= 20:
                res.append(intToWords(num // 10 * 10))
                num %= 10
            if num > 0:
                res.append(intToWords(num))
            return res

        if num == 0:
            return "Zero"

        blockWords = ["", "Thousand", "Million", "Billion", "Trillion", "Quadrillion", "Quintillion"]
        blocks = seperateToThree(num)
        ans = []
        for i in range(len(blocks)):
            if blocks[i]:
                ans += threeToWords(blocks[i])
                if blockWords[len(blocks) - i - 1]:
                    ans.append(blockWords[len(blocks) - i - 1])
        
        return " ".join(ans).strip()

if __name__ == '__main__':
    s = Solution()
    num = int(input())
    print(s.numberToWords(num))