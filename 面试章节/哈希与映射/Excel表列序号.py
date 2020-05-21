# 这道题非常简单，将字符串倒置后就可以按照二十六进制的处理方法处理；
# 48ms, 36.26%; 13.7MB, 0%
class Solution:
    def titleToNumber(self, s: str) -> int:
        rev = s[::-1]
        ans = 0
        digit = 1
        for i in range(len(rev)):
            ans += (ord(rev[i])-ord('A')+1)*digit
            digit *= 26
        return ans