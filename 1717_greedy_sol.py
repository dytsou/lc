class Solution(object):
    def maximumGain(self, s, x, y):
        a_count = 0
        b_count = 0
        less_point = min(x, y)
        result = 0

        for c in s:
            if c > 'b': # c != 'a' and c != 'b' for better performance
                # adding the points which is not gained in the previous steps
                # i.e. remove ab if x < y or ba if y < x
                result += min(a_count, b_count) * less_point
                a_count = 0
                b_count = 0
            elif c == 'a':
                if x < y and b_count > 0: # can make ba pair
                    b_count -= 1 # remove b
                    result += y
                else: # can't make ba pair
                    a_count += 1
            elif c == 'b':
                if x > y and a_count > 0: # can make ab pair
                    a_count -= 1 # remove a
                    result += x
                else: # can't make ab pair
                    b_count += 1
        # adding the points which is not gained in the previous steps
        result += min(a_count, b_count) * less_point 
        return result
             
if __name__ == '__main__':
    s = Solution()
    print(s.maximumGain(input(), int(input()), int(input())))