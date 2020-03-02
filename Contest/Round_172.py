# Maximum 69 Number
class Solution:
    def maximum69Number (self, num: int) -> int:
        ans = num
        pos = -1
        count = 0
        while ans >= 10:
            if ans % 10 == 6:
                pos = count
            ans = ans // 10
            count = count+1
        if ans == 6:
            pos = count
        if pos == -1:
            return num
        else:
            return num+3*(10**pos)

