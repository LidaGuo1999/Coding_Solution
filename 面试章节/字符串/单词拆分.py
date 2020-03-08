from typing import List

# 该题第一直觉应该是使用递归进行求解，找到第一刀切下去的位置，然后讲后面的子字符串当成一个全新的字符串来进行处理
# 由于递归的原因，测试时造成了TLE，说明其不是理想的解法
class Solution1:
    def __init__(self):
        self.accept = set()
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        self.accept = set()
        if len(s) == 0:
            return True
        if s in self.accept:
            return True
        for i in range(len(s)):
            if s[0:i+1] in self.accept and s[i+1:len(s)] in self.accept:
                self.accept.add(s)
                return True
            elif s[0:i+1] in self.accept and self.wordBreak(s[i+1:len(s)], wordDict):
                self.accept.add(s)
                return True
            elif s[0:i+1] in wordDict and s[i+1:len(s)] in self.accept:
                self.accept.add(s)
                return True
            elif s[0:i+1] in wordDict and self.wordBreak(s[i+1:len(s)], wordDict):
                self.accept.add(s)
                return True
        return False

# 第二种方法使用了动态规划，将整个字符串按照长度来进行处理，即先看所有长度为1的字符串是否符合，再看长度为2的，一直到长度为len(s)的。但是可见效果比较差。
# 376ms, 0%; 13.5MB, 19.88%
class Solution2:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        # Initialization
        dp = []
        for i in range(len(s)+1):
            if i == 0:
                dp.append([1]*(len(s)+1))
            dp.append([0]*(len(s)+1-i))
        print(dp)
        for i in range(len(s)):
            if s[i] in wordDict:
                dp[1][i] = 1
        
        # Begin Dynamic Planning
        for i in range(2, len(s)+1):
            for j in range(0, len(s)-i+1):
                for k in range(j+1, j+i+1):
                    print('{} {} {}'.format(i, j, k))
                    if (dp[k-j][j] == 1 or s[j:k] in wordDict) and (dp[j+i-k][k] == 1 or s[k:j+i] in wordDict):
                        dp[i][j] = 1
                        break
        
        # Return result
        print(dp)
        return True if dp[len(s)][0] == 1 else False

# 第三种方法也是动态规划，但是少了一层循环，基本思路如下：利用dp[i]代表字符串的前i个字符组成的字符串是否符合要求，如果符合要求，
# 那么就遍历字符串的第i+1到第j个字符（i+1<=j<=len(s)），如果s[i+1:j]存在于列表中，那么dp[j]就被置为True
# 40ms, 87.32%; 13.7MB, 19.74%
class Solution3:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        wordSet = set(wordDict)
        dp = [False] * (n+1)
        dp[0] = True
        for i in range(n):
            for j in range(i+1, n+1):
                if dp[i] and s[i:j] in wordSet:
                    dp[j] = True
        return dp[-1]

if __name__ == "__main__":
    solution = Solution3()
    s = 'leetcode'
    wordDict = ['leet', 'code']
    print(solution.wordBreak(s, wordDict))