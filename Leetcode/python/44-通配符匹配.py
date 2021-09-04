from AutoTest import AutoTest

class Solution1:
    def isMatch(self, s, p):
        '''
        这是一道比较难的动态规划问题，关键点在于让s的前i个字符和p的前j个字符进行匹配，需要考虑可能出现的各种情况。最后还需要考虑s和p为空的临界状态。
        648ms, 57.86%; 23.4MB, 26.73%;
        '''
        if len(p) == 0:
            if len(s) == 0: return True
            else: return False

        dp = [[0 for i in range(len(s)+1)] for i in range(len(p))]
        appear = [2**32-1 for i in range(len(p))]
        if p[0] == '*':
            for j in range(len(s)+1):
                dp[0][j] = 1
            appear[0] = 0
        else:
            if len(s) > 0 and (p[0] == '?' or p[0] == s[0]):
                dp[0][1] = 1
                appear[0] = 1

        for i in range(1, len(p)):
            if p[i] == '*' and dp[i-1][0] == 1:
                dp[i][0] = 1
            for j in range(1, len(s)+1):
                if p[i] == '*':
                    if appear[i-1] <= j:
                        dp[i][j] = 1
                        appear[i] = min(appear[i], j)
                else:
                    if (p[i] == '?' or p[i] == s[j-1]) and dp[i-1][j-1] == 1:
                        dp[i][j] = 1
                        appear[i] = min(appear[i], j)
        
        return dp[-1][-1] == 1

class Solution2:
    '''
    这种解法很巧妙，但是不够普遍，使用了贪心策略。将p看作*u1*u2*...*un*的结构，再在s中贪心地匹配所有ui即可。不过需要特殊处理p的开头或者结尾不是*的情况。所考虑的部分很多，因此普遍性较低。
    48ms, 96.49%; 15MB, 95.64%;
    '''
    def isMatch(self, s, p):
        if len(p) == 0: return len(s) == 0
        def allStar(st, left, right): return all(st[i] == '*' for i in range(left, right))
        def match(x, y): return y == '?' or x == y

        # 主要处理p的结尾不是*的情况
        sRight, pRight = len(s), len(p)
        while sRight > 0 and pRight > 0 and p[pRight-1] != '*':
            if match(s[sRight-1], p[pRight-1]):
                sRight -= 1
                pRight -= 1
            else:
                return False
        
        if pRight == 0: return sRight == 0

        # 这一部分将值设为-1是为了考虑p的开头不是*的情况
        sIndex, pIndex, sRecord, pRecord = 0, 0, -1, -1
        while sIndex < sRight and pIndex < pRight:
            if p[pIndex] == '*':
                pIndex += 1
                pRecord = pIndex
                sRecord = sIndex
            elif match(s[sIndex], p[pIndex]):
                sIndex += 1
                pIndex += 1
            elif sRecord != -1 and sRecord+1 < sRight:
                sRecord += 1
                sIndex = sRecord
                pIndex = pRecord
            else:
                return False
        
        # 如果s已经遍历完但是p还有剩余，那么p的剩下部分必须全部是*
        return allStar(p, pIndex, pRight)



if __name__ == '__main__':
    funcName = 'isMatch'
    paramNum = 2
    cases = [
        {'s': 'aa', 'p': 'a'},
        {'s': 'aa', 'p': '*'},
        {'s': 'cb', 'p': '?a'},
        {'s': 'adceb', 'p': '*a*b'},
        {'s': 'acdcb', 'p': 'a*c?b'},
        {'s': '', 'p': ''},
        {'s': '', 'p': 'a'},
        {'s': 'babbaabaabaaaaabbbbabaababbababbbaabbbbbbbbbababaabbabbaaabaaabbababbaaabbbbababbbaaababbbbababababaaaabbbbabbbabbabbbaaabaabaababbababbbabaaabbbbaaabbbabbabbbbaabaabbabaabababbbababaaabaaabbbabbaaaabab', 'p': "baa*b*ab*aa**bb*bbbaab***b*abbb*bbb*b*aa*b*b*ab*********ab*b***abb***a*bbb***a*a*b*baa*b***bb*b**ba*b*"},
        {'s': 'ab', 'p': '?*'}
    ]
    answers = [
        {'rtn': False},
        {'rtn': True},
        {'rtn': False},
        {'rtn': True},
        {'rtn': False},
        {'rtn': True},
        {'rtn': False},
        {'rtn': False},
        {'rtn': True}
    ]
    keyNames = [['s', 'p'], 'rtn']

    s1 = Solution2()
    autotest = AutoTest(s1, funcName, paramNum)
    autotest.test({'cases': cases, 'answers': answers}, keyNames)
    print(s1.isMatch('ab', '?*'))