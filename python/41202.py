class Solution:            
    def countPairs(self, nums: list[int]) -> int:
        def check_swap(num1: str, num2: str) -> bool:
            diff_digit = []
            if len(num1) > len(num2):
                num2 = '0' * (len(num1) - len(num2)) + num2
            elif len(num1) < len(num2):
                num1 = '0' * (len(num2) - len(num1)) + num1
            for i in range(len(num1)):
                if num1[i] != num2[i]:
                    diff_digit.append(i)
            if len(diff_digit) == 2:
                if num1[diff_digit[0]] == num2[diff_digit[1]] and num1[diff_digit[1]] == num2[diff_digit[0]]:
                    return True
            return False
        
        res = 0
        nums = sorted(nums)
        nums_str = [str(num) for num in nums]
        for i in range(len(nums_str)):
            for j in range(i + 1, len(nums_str)):
                if nums_str[i] == nums_str[j]:
                    res += 1
                    continue
                res += check_swap(nums_str[i], nums_str[j])
        return res