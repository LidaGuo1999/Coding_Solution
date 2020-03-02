from typing import List

# 该题第一直觉应该也是使用递归进行求解
class Solution:
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

    

if __name__ == "__main__":
    solution = Solution()
    s = 'catsandog'
    wordDict = ["cats", "dog", "sand", "and", "cat"]
    print(solution.wordBreak(s, wordDict))