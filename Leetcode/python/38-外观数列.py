from AutoTest import AutoTest
'''
给定一个正整数 n ，输出外观数列的第 n 项。

「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。

你可以将其视作是由递归公式定义的数字字符串序列：

countAndSay(1) = "1"
countAndSay(n) 是对 countAndSay(n-1) 的描述，然后转换成另一个数字字符串。

'''

class Solution:
    def countAndSay(self, n):
        '''
        简单的递归，主要的递归单元就是计算每一步字符串的表示。
        40ms, 91.96%; 15MB, 39.96%;
        '''
        def say(s):
            rtn, cur, cnt = '', '', 0
            for l in s:
                if cur == '':
                    cur = l
                    cnt = 1
                else:
                    if l == cur:
                        cnt += 1
                    else:
                        rtn += str(cnt)+cur
                        cur = l
                        cnt = 1
            rtn += str(cnt)+cur
            
            return rtn
        
        cur = '1'
        for i in range(n-1):
            cur = say(cur)
        
        return cur

if __name__ == '__main__':
    funcName = 'countAndSay'
    paramNum = 1
    cases = [
        {'n': 1},
        {'n': 2},
        {'n': 3},
        {'n': 4},
        {'n': 10}
    ]
    answers = [
        {'rtn': '1'},
        {'rtn': '11'},
        {'rtn': '21'},
        {'rtn': '1211'},
        {'rtn': "13211311123113112211"}
    ]
    keyNames = [['n'], 'rtn']

    s1 = Solution()
    autotest = AutoTest(s1, funcName, paramNum)
    autotest.test({'cases': cases, 'answers': answers}, keyNames)

    #print(s1.countAndSay(2))