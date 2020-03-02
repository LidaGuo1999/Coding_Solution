# 基本思想是利用递归的方法，从左到右依次遍历字符串，找到第一次切断的分割点，找到后将后面的当成一个新的字符串进行处理，从而实现递归处理。
# 80ms, 78.03%; 13.7MB, 34.67%
from typing import List

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        result = []
        if len(s) == 1:
            return [[s]]
        if self.judge(s):
            result.append([s])
        for i in range(1, len(s)):
            if self.judge(s[0:i]):
                subResult = self.partition(s[i:len(s)])
                for j in subResult:
                    result.append([s[0:i]] + j)
        return result
        

    def judge(self, s: str) -> bool:
        i = 0
        j = len(s)-1
        while i < j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True
        
if __name__ == "__main__":
    solution = Solution()
    s = 'acdcaabba'
    print(solution.partition(s))