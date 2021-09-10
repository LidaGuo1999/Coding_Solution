from AutoTest import AutoTest

'''
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
问总共有多少条不同的路径？
'''

class Solution:
    '''
    该解法使用的是排列组合，共m+n-2个位置，需要在里面挑出m-1个位置，因此用组合数C(m+n-2)(m-1)即可。
    40ms, 28.89%; 15MB, 44.42%;
    '''
    def uniquePaths(self, m, n):
        numerator, denominator = 1, 1
        for i in range(m+n-2, n-1, -1): numerator *= i
        for i in range(1, m, 1): denominator *= i
        
        return numerator // denominator

if __name__ == '__main__':
    funcName = 'uniquePaths'
    paramNum = 2
    cases = [
        {'param1': 3, 'param2': 7},
        {'param1': 3, 'param2': 2},
        {'param1': 7, 'param2': 3},
        {'param1': 3, 'param2': 3},
        {'param1': 1, 'param2': 1},
    ]
    answers = [
        {'rtn': 28},
        {'rtn': 3},
        {'rtn': 28},
        {'rtn': 6},
        {'rtn': 1},

    ]
    keyNames = [['param'+str(i+1) for i in range(paramNum)], 'rtn']

    s1 = Solution()
    autotest = AutoTest(s1, funcName, paramNum)
    autotest.test({'cases': cases, 'answers': answers}, keyNames)
    print(s1.uniquePaths(3,3))