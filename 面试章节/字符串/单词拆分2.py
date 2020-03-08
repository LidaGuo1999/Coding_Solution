from typing import List

# 第一感觉还是使用了递归的方法进行求解，找到第一刀分割的位置，然后将后面的字符串当作子字符串进行递归。
# 但是提交过程中仍旧TLE，说明这不是理想的解题方法。
class Solution1:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        doubleList = self.recursion(s, wordDict)
        check = []
        for i in doubleList:
            temps = ''
            for j in i:
                temps += j
            if temps == s:
                check.append(i)
        result = []
        for i in check:
            sep = ''
            for j in i:
                sep = sep+j+' '
            sep = sep.strip()
            result.append(sep)
        return result
                
    def recursion(self, s: str, wordDict: List[str]) -> List[List[str]]:
        result = []
        if len(s) == 1:
            return [[s]] if s in wordDict else [[]]
        for i in range(len(s)-1):
            if s[0:i+1] in wordDict:
                subResult = self.recursion(s[i+1:len(s)], wordDict)
                for j in subResult:
                    result.append([s[0:i+1]]+j)
        if s in wordDict:
            result.append([s])

        return result 

# 经过进一步的思考，我认为递归（或者叫回溯）应该是可以完成的，唯一的问题在于我们对于子字符串进行了太多不必要的递归，所以可以考虑使用记忆化回溯的方法.
# 140ms, 11.81%; 13.6MB, 29.47%
class Solution2:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        memory = {}
        result = []
        if not self.judge(s, wordDict):
            return result
        doubleList = self.recursion(s, wordDict, memory)
        check = []
        for i in doubleList:
            temps = ''
            for j in i:
                temps += j
            if temps == s:
                check.append(i)
        for i in check:
            sep = ''
            for j in i:
                sep = sep+j+' '
            sep = sep.strip()
            result.append(sep)
        return result
                
    def recursion(self, s: str, wordDict: List[str], memory) -> List[List[str]]:
        result = []
        if len(s) == 1:
            return [[s]] if s in wordDict else [[]]
        for i in range(len(s)-1):
            if s[0:i+1] in wordDict and s[i+1:len(s)] in memory:
                subResult = memory[s[i+1:len(s)]]
                for j in subResult:
                    result.append([s[0:i+1]]+j)
            elif s[0:i+1] in wordDict and s[i+1:len(s)] not in memory:
                subResult = self.recursion(s[i+1:len(s)], wordDict, memory)
                memory[s[i+1:len(s)]] = subResult
                for j in subResult:
                    result.append([s[0:i+1]]+j)
        if s in wordDict:
            result.append([s])

        return result 
    
    def judge(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        dp = [False] * (n+1)
        dp[0] = True
        for i in range(n):
            for j in range(i+1, n+1):
                if dp[i] and s[i:j] in wordDict:
                    dp[j] = True
        return dp[-1]

class Solution3:
    